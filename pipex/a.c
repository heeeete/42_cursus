#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define buff 1024

int main()
{
	int fd;

	fd = open("a.txt", O_RDWR | O_CREAT, 0644);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror("er");
	printf("asjddasdj");
}