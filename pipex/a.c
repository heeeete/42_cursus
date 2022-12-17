#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define buff 1024

int main()
{
	int fd[2];
	char a[buff];
	pid_t pid;

	if (pipe(fd) == -1)
		perror("");
	pid = fork();
	if (pid == -1)
		perror("");
	else if (pid == 0)
	{
		write(fd[1], "hacho", buff);
		sleep(1);
		read(fd[0], a, buff);
		printf("자식 : %s\n", a);
	}
	else
	{
		read(fd[0], a, buff);
		printf("부모 : %s\n", a);
		write(fd[1], "huipark", buff);
	}
}
