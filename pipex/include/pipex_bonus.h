/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:43:36 by huipark           #+#    #+#             */
/*   Updated: 2022/12/27 23:58:11 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

# define READ 0
# define WRITE 1

typedef struct s_files
{
	int		infile;
	int		outfile;
	int		pid;
	int		read_fd[2];
	int		write_fd[2];
	int		proc_cnt;
	int		argc;
	char	**path;
	char	**cmd_options;
	char	*cmd;
}			t_files;

void	ft_perror(void);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_close(int fd, int fd2);
void	ft_dup2(int fd, int fd2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);