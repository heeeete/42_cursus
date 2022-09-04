/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:53:38 by huipark           #+#    #+#             */
/*   Updated: 2022/09/04 20:02:56 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	if (!src)
		return (0);
	len = 0;
	while (src[len])
		len++;
	if (size != 0)
	{
		while (*src && size > 1)
		{
			*dest = *src;
			dest++;
			src++;
			size--;
		}
		*dest = '\0';
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c && *s == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			dest_len;
	size_t			src_len;
	unsigned int	i;

	i = 0;
	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (src[i] && dest_len + i + 1 < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (size > dest_len)
		return (dest_len + src_len);
	return (src_len + size);
}

char	*ft_strdup(const char *s1)
{
	int			i;
	size_t		len;
	char		*dest;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcat(dest, s2, s1_len + s2_len + 1);
	return (dest);
}
