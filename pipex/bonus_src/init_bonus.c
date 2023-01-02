/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:12:31 by huipark           #+#    #+#             */
/*   Updated: 2023/01/02 22:12:58 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	init(t_files *files, int argc, char *argv[], char *envp[])
{
	files->argc = argc;
	files->proc_cnt = 2;
	if (pipe(files->read_fd) == -1)
		ft_perror("pipe error", 1);
	close(files->read_fd[WRITE]);
	get_path(files, envp);
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		files->outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (files->outfile == -1)
			ft_perror(argv[argc - 1], 1);
		here_doc(files, argv);
	}
	else
	{
		files->infile = open(argv[1], O_RDONLY);
		if (files->infile == -1)
			ft_perror(argv[1], 1);
		files->outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (files->outfile == -1)
			ft_perror(argv[argc - 1], 1);
	}
}
