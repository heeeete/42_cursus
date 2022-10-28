#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	int		size = 1;
	char	line[6000000];
	char	*tempaddress;
	char	*value;
	int		i = 0;

	if (line[0] != '\0')
	{
		while (line[i] != '\0')
			line[i++] = '\0';
	}
	i = 0;
	if (fd < 0)
		return NULL;
	while (size)
	{
		size = read(fd, &line[i], 1);
		if (line[i] == '\n' || size == -1 || size ==0)
		{
			tempaddress = value;
			value = ft_strdup(line);
			free (tempaddress);
			break;
		}
		i++;
	}
	return (value);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	char *str2 = get_next_line(fd);
	printf("%s", str2);
	char *str3 = get_next_line(fd);
	printf("%s", str3);
	char *str4 = get_next_line(fd);
	printf("%s", str4);
	char *str5 = get_next_line(fd);
	printf("%s", str5);
	char *str6 = get_next_line(fd);
	printf("%s", str6);
	char *str7 = get_next_line(fd);
	printf("%s", str7);
	char *str8 = get_next_line(fd);
	printf("%s", str8);
	char *str9 = get_next_line(fd);
	printf("%s", str9);
}