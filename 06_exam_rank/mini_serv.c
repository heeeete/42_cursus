#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>

typedef struct s_client
{
	int id;
	char msg[1024];
} t_client;
fd_set sockets, read_sock, write_sock;
char read_buf[120000], write_but[120000];
int next_id = 0, max_fd;
t_client clients[1024 * 4];

void err(char *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

void send_all(int not )
{
	for (int i = 0; i < max_fd; i++)
		if (FD_ISSET(i, &write_sock) && i != not )
			send(i, write_but, strlen(write_but), 0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		err("Wrong number arguments\n");

	int sockfd;
	struct sockaddr_in servaddr, cli;
	socklen_t len;

	sockfd = socket(2, 1, 0);

	if (sockfd == -1)
		err("Fatal Error\n");
	len = sizeof(cli);
	max_fd = sockfd;
	FD_ZERO(&sockets);
	FD_SET(sockfd, &sockets);
	bzero(clients, sizeof(clients));
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = 2;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err("Fatal Error\n");
	if (listen(sockfd, 10) < 0)
		err("Fatal Error\n");

	while (1)
	{
		read_sock = write_sock = sockets;
		if (select(max_fd + 1, &read_sock, &write_sock, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (FD_ISSET(fd, &read_sock) && fd == sockfd)
			{
				int connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
				if (connfd < 0)
					continue;
				clients[connfd].id = next_id++;
				max_fd = connfd > max_fd ? connfd : max_fd;
				FD_SET(connfd, &sockets);
				sprintf(write_but, "server: client %d just arrived\n", clients[connfd].id);
				send_all(connfd);
				break;
			}
			if (FD_ISSET(fd, &read_sock) && fd != sockfd)
			{
				int res = recv(fd, read_buf, 65536, 0);
				if (res <= 0)
				{
					sprintf(write_but, "server: client %d just left\n", clients[fd].id);
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
							sprintf(write_but, "client %d: %s\n", clients[fd].id, clients[fd].msg);
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

