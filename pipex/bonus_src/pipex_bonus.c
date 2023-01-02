#include "../include/pipex_bonus.h"

char	*get_vaild_cmd(char **path, char *cmd)
{
	int	i;
	char	*temp_address;
	char	*temp_path;
	char	*temp_cmd;

	i = 0;
	temp_path = NULL;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	temp_cmd = ft_strjoin("/", cmd);
	if (!temp_cmd)
		exit (1);
	while (path[i])
	{
		temp_address = temp_path;
		temp_path = ft_strjoin(path[i], temp_cmd);
		free (temp_address);
		if (access(temp_path, X_OK) == 0)
			return (temp_path);
		i++;
	}
	return (NULL);
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

void	here_doc(t_files *files, char *argv[])
{
	char	*line;
	if (pipe(files->write_fd) == -1)
		ft_perror("pipe error", 1);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
			break;
		write(files->write_fd[WRITE], line, ft_strlen(line));
		free(line);
	}
	files->read_fd[0] = files->write_fd[0];
	close(files->write_fd[WRITE]);
	files->proc_cnt = 3;
}

void	init(t_files *files, int argc, char *argv[], char *envp[])
{
	files->argc = argc;
	files->proc_cnt = 2;
	if (pipe(files->read_fd) == -1)
		ft_perror("pipe error", 1);
	get_path(files, envp);
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		files->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		if (files->outfile == -1)
			ft_perror(argv[argc - 1], 1);
		here_doc(files, argv);
	}
	else
	{
		files->infile = open(argv[1], O_RDONLY);
		if (files->infile == -1)
			ft_perror(argv[1], 1);
		files->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (files->outfile == -1)
			ft_perror(argv[argc - 1], 1);
	}
}

void	execute(t_files *files, char *argv[], char *envp[])
{
	files->cmd_options = ft_split(argv[files->proc_cnt], ' ');
	if (!files->cmd_options)
		ft_perror("empty string", 1);
	files->cmd = get_vaild_cmd(files->path, files->cmd_options[0]);
	if (!files->cmd)
		ft_perror("not valid cmd", 1);
	if (files->proc_cnt == 2)
	{
		ft_dup2(files->infile, files->write_fd[WRITE]);
		ft_close(files->infile, files->write_fd[WRITE]);
		execve(files->cmd, files->cmd_options, envp);
	}
	else if (files->proc_cnt == files->argc - 2)
	{

		ft_dup2(files->read_fd[READ], files->outfile);
		ft_close(files->read_fd[READ], files->outfile);
		execve(files->cmd, files->cmd_options, envp);
	}
	else
	{
		ft_dup2(files->read_fd[READ], files->write_fd[WRITE]);
		ft_close(files->read_fd[READ], files->write_fd[WRITE]);
		execve(files->cmd, files->cmd_options, envp);
	}
}


void	run_command(t_files *files, char *argv[], char *envp[])
{
	close(files->read_fd[WRITE]);
	while (files->proc_cnt < files->argc - 1)
	{
		if (pipe(files->write_fd) == -1)
			ft_perror("pipe error", 1);
		files->pid = fork();
		if (files->pid == -1)
			ft_perror("fork error", 1);
		else if (files->pid == 0)
			execute(files, argv, envp);
		else
		{
			close(files->write_fd[WRITE]);
			files->read_fd[0] = files->write_fd[0];
			files->proc_cnt++;
		}
	}
}


int main(int argc, char *argv[], char *envp[])
{
	t_files	files;

	if (argc < 5)
		exit(1);
	init(&files, argc, argv, envp);
	run_command(&files, argv, envp);
	wait(0);
	exit(0);
}