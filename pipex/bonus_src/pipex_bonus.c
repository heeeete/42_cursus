#include "../include/pipex_bonus.h"
#include <string.h>
#include <errno.h>

char	*get_vaild_cmd(char **path, char *cmd)
{
	int	i;
	char	*temp_address;
	char	*temp_path;
	char	*temp_cmd;

	i = 0;
	temp_path = NULL;
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	temp_cmd = ft_strjoin("/", cmd);
	if (!temp_cmd)
		return (0);
	while (path[i])
	{
		temp_address = temp_path;
		temp_path = ft_strjoin(path[i], temp_cmd);
		free (temp_address);
		if (access(temp_path, X_OK) != -1)
			break ;
		i++;
	}
	return (temp_path);
}

void	get_path(t_files *files, char *envp[])
{
	int	i = 0;
	
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			envp[i] += 5;
			break;
		}
		i++;
	}
	files->path = ft_split(envp[i], ':');
}

void	init(t_files *files, int argc, char *argv[], char *envp[])
{
	files->infile = open(argv[1], O_RDONLY);
	files->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (files->outfile == -1 || files->infile == -1)
		ft_perror();
	files->argc = argc;
	files->proc_cnt = 2;
	get_path(files, envp);
	files->cmd_options = ft_split(argv[2], ' ');
	files->cmd_options2 = ft_split(argv[3], ' ');
	files->f_cmd = get_vaild_cmd(files->path, files->cmd_options[0]);
	files->s_cmd = get_vaild_cmd(files->path, files->cmd_options2[0]);
}

void	run_command(t_files files, char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_perror();
	while (files.proc_cnt < files.argc - 1)
	{

	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_files	files;

	if (argc != 5)
		exit(1);
	init(&files, argc, argv, envp);
	run_command(files, envp);
}