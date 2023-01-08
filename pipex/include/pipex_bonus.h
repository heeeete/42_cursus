/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:14:34 by huipark           #+#    #+#             */
/*   Updated: 2023/01/03 14:33:29 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line_bonus.h"

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

void	init(t_files *files, int argc, char *argv[], char *envp[]);
void	here_doc(t_files *files, char *argv[]);
void	ft_perror(char *msg, int exit_status);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_close(int fd, int fd2);
void	ft_dup2(int fd, int fd2);
void	get_path(t_files *files, char *envp[]);
char	*ft_strdup(const char *s1);

#endif