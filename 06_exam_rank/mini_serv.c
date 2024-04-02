#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct s_client
{
	int id;
	char msg[110000];
} t_client;

t_client clients[1024];
const int BUF_SIZE = 42 * 4096;
char read_buf[BUF_SIZE], write_buf[BUF_SIZE];
fd_set sockets, read_fd, wirte_fd;
int max_fd = 0, next_id = 0;
unsigned int ipAddr;

void set_ip(unsigned int *ip)
{
	char a = 127, b = 0, c = 1;
	*ip = a << 24 | b << 16 | b < 8 | c;
}

void send_all(int is_not)
{
	for (int i = 0; i <= max_fd; i++)
	{
		if (FD_ISSET(i, &wirte_fd) && i != is_not)
			send(i, write_buf, strlen(write_buf), 0);
	}
}

void err(char *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		err("Wrong number of input\n");
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		err("Fatal error");
	max_fd = sock;
	FD_ZERO(&sockets);
	FD_SET(sock, &sockets);
	bzero(clients, sizeof(clients));
	set_ip(&ipAddr);

	struct sockaddr_in servaddr;
	socklen_t len = sizeof(servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(ipAddr);
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(sock, (const struct sockaddr *)&servaddr, len) < 0)
		err("Fatal error");
	if (listen(sock, 42) < 0)
		err("Fatal error");

	while (1)
	{
		read_fd = wirte_fd = sockets;
		if (select(max_fd + 1, &read_fd, &wirte_fd, NULL, NULL) < 0)
			continue;
		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (FD_ISSET(fd, &read_fd) && fd == sock)
			{
				int connfd = accept(fd, (struct sockaddr *)&servaddr, &len);
				if (connfd < 0)
					continue;
				FD_SET(connfd, &sockets);
				clients[connfd].id = next_id++;
				max_fd = connfd > max_fd ? connfd : max_fd;
				sprintf(write_buf, "server: client %d just arrived\n", clients[connfd].id);
				send_all(connfd);
				break;
			}
			else if (FD_ISSET(fd, &read_fd))
			{
				int res = recv(fd, read_buf, BUF_SIZE, 0);
				if (res <= 0)
				{
					sprintf(write_buf, "server: client %d just left\n", clients[fd].id);
					send_all(fd);
					FD_CLR(fd, &sockets);
					close(fd);
					break;
				}
				else
				{
					for (int i = 0, j = strlen(clients[fd].msg); i < res; i++, j++)
					{
						clients[fd].msg[j] = read_buf[i];
						if (clients[fd].msg[j] == '\n')
						{
							clients[fd].msg[j] = '\0';
							sprintf(write_buf, "client %d: %s\n", clients[fd].id, clients[fd].msg);
							send_all(fd);
							bzero(clients[fd].msg, sizeof(clients[fd].msg));
							j = -1;
						}
					}
					break;
				}
			}
		}
	}
	return 0;
}
