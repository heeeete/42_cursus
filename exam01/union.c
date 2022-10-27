#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 1;
	int j = 0;
	int c[128];
	
	while(j <= 127)
		c[j++] = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[i])
		{
			while (argv[i][j])
			{
				if (c[argv[i][j]] == 0)
				{
					write(1, &argv[i][j], 1);
					c[argv[i][j]] = 1;
				}
				j++;
			}
			i++;
			j = 0;
		}
	}
	return 0;
}