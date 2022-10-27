#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int arr[128];

	while (j <= 127)
		arr[j++] = 0;
	j = 0;

	if (argc == 3)
	{
		while (argv[1][j])
		{
			while (argv[2][i])
			{
				if (argv[1][j] == argv[2][i] && arr[argv[1][j]] == 0)
				{
					write (1, &argv[1][j], 1);
					arr[argv[1][j]] = 1;
					break;
				}
				i++;
			}
			i = 0;
			j++;
		}
	}
}