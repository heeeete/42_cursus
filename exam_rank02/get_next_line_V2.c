#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i = -1;
	int		len = 0;
	char	*dest;

	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	while (src[++i])
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return (dest);
}

char	*get_next_line(int fd)
{
	char buffer;
	char str[7000000];
	int i;
	int size;


	if (fd < 0)
		return (0);
	i = 0;
	if (str[0] != '\0')
	{
		while (str[i] != '\0')
			str[i++] = '\0';
	}
	i = 0;
	size = read(fd, &buffer, 1);
	while (size > 0)
	{
		str[i++] = buffer;
		if (buffer == '\n')
			break;
		size = read(fd, &buffer, 1);
		// if (size == 0 || size == -1)
		// 	return (NULL);
	}
	str[i] = 0;
	if (size <= 0 && i == 0)
		return 0;
	return (ft_strdup(str));
}
