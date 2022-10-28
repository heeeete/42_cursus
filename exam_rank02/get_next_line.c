#include <unistd.h>
#include <stdlib.h>

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

	value = NULL;
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
		if (line[i] == '\n')
		{
			tempaddress = value;
			value = ft_strdup(line);
			free (tempaddress);
			break;
		}
		if (size == 0 || size == -1)
			return NULL;
		i++;
	}
	return (value);
}
