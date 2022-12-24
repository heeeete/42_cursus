/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:47:07 by huipark           #+#    #+#             */
/*   Updated: 2022/12/25 00:11:19 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_perror(void)
{
	perror("error ");
	exit(1);
}

void	ft_close(int fd, int fd2)
{
	close(fd);
	close(fd2);
}

void	ft_dup2(int fd, int fd2)
{
	dup2(fd, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
}

char	*ft_strdup(const char *s1)
{
	int			i;
	const int	len = ft_strlen(s1);
	char		*dest;

	i = 0;
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