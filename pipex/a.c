#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define buff 1024

int main()
{
	int fd[2];
	pid_t pid;
	char	*str;

	pipe(fd);
	str = malloc(buff);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		printf("asd\n");
		exit(0);
	}
	else
		wait(0);
	
	pid = fork();
	if(pid == 0)
	{
		close(fd[1]);
		int a = read(fd[0], str, buff);
		str[a] = 0;
		printf("%s", str);
	}
	else
		wait(0);
}