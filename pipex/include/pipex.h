/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:43:36 by huipark           #+#    #+#             */
/*   Updated: 2022/12/20 19:48:11 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

# define READ 0
# define WRITE 1

typedef struct s_files
{
	int		infile;
	int		outfile;
	char	**path;
	char	**temp1_cmd;
	char	**temp2_cmd;
	char	*f_cmd;
	char	*s_cmd;
}			t_files;

void	ft_perror(char *msg);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_close(int fd, int fd2);