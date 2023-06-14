#include "../include/cub3d.h"

void	*wrap_malloc(size_t s)
{
	void	*ret;

	ret = malloc(s);
	if (ret == NULL)
		error ("MALLOC ERROR", NULL);
	return (ret);
}

void	error(char *msg, char *msg2) {
	if (msg2)
		printf("\"%s\" %s\n", msg2, msg);
	else
		printf("%s\n", msg);
	exit(1);
}
