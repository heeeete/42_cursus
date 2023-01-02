/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:47:07 by huipark           #+#    #+#             */
/*   Updated: 2023/01/02 22:36:32 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_perror(char *msg, int exit_status)
{
	perror(msg);
	exit(exit_status);
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
	ft_close(fd, fd2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}

void	here_doc(t_files *files, char *argv[])
{
	char	*line;

	if (pipe(files->write_fd) == -1)
		ft_perror("pipe error", 1);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || !ft_strncmp(line, argv[2], ft_strlen(argv[2])))
		{
			free(line);
			break ;
		}
		write(files->write_fd[WRITE], line, ft_strlen(line));
		free(line);
	}
	files->read_fd[0] = files->write_fd[0];
	close(files->write_fd[WRITE]);
	files->proc_cnt = 3;
}
