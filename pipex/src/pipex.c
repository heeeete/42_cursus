/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:24:44 by huipark           #+#    #+#             */
/*   Updated: 2023/01/03 14:37:23 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_vaild_cmd(char **path, char *cmd)
{
	int		i;
	char	*temp_address;
	char	*temp_path;
	char	*temp_cmd;

	i = 0;
	temp_path = NULL;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	temp_cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		temp_address = temp_path;
		temp_path = ft_strjoin(path[i], temp_cmd);
		free (temp_address);
		if (access(temp_path, X_OK) == 0)
		{
			free(temp_cmd);
			return (temp_path);
		}
		i++;
	}
	free(temp_cmd);
	return (NULL);
}

void	get_path(t_files *files, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			envp[i] += 5;
			break ;
		}
		i++;
	}
	files->path = ft_split(envp[i], ':');
}

void	init(t_files *files, char *argv[], char *envp[])
{
	files->infile = open(argv[1], O_RDONLY);
	if (files->infile == -1)
		ft_perror(argv[1], 1);
	files->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (files->outfile == -1)
		ft_perror(argv[4], 1);
	get_path(files, envp);
	files->cmd_options = ft_split(argv[2], ' ');
	files->cmd_options2 = ft_split(argv[3], ' ');
	if (!files->cmd_options || !files->cmd_options2)
		ft_perror("empty string", 1);
	files->f_cmd = get_vaild_cmd(files->path, files->cmd_options[0]);
	files->s_cmd = get_vaild_cmd(files->path, files->cmd_options2[0]);
	if (!files->f_cmd || !files->s_cmd)
		ft_perror("not valid cmd", 1);
}

void	run_command(t_files files, char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_perror("pipe error", 1);
	pid = fork();
	if (pid == -1)
		ft_perror("fork error", 1);
	else if (pid > 0)
	{
		close(fd[WRITE]);
		ft_dup2(fd[READ], files.outfile);
		wait(0);
		execve(files.s_cmd, files.cmd_options2, envp);
	}
	else
	{
		close(fd[READ]);
		ft_dup2(files.infile, fd[WRITE]);
		execve(files.f_cmd, files.cmd_options, envp);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_files	files;

	if (argc != 5)
		exit(1);
	init(&files, argv, envp);
	run_command(files, envp);
}
