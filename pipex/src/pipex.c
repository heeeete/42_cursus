#include "../include/pipex.h"
#include <string.h>
#include <errno.h>

char	*get_vaild_cmd(char **path, char *cmd)
{
	int	i;
	char	*temp_address;
	char	*temp_path;

	i = 0;
	temp_path = NULL;
	while (path[i])
	{
		temp_address = temp_path;
		temp_path = ft_strjoin(path[i], cmd);
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

void	init(t_files *files, char *argv[], char *envp[])
{
	char	*f_cmd;
	char	*s_cmd;

	files->infile = open(argv[1], O_RDONLY);
	if (files->infile == -1)
		ft_perror("ERROR");
	files->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (files->outfile == -1)
		ft_perror("ERROR");
	get_path(files, envp);
	files->temp1_cmd = ft_split(argv[2], ' ');
	files->temp2_cmd = ft_split(argv[3], ' ');
	f_cmd = ft_strjoin("/", files->temp1_cmd[0]);
	s_cmd = ft_strjoin("/", files->temp2_cmd[0]);
	files->f_cmd = get_vaild_cmd(files->path, f_cmd);
	files->s_cmd = get_vaild_cmd(files->path, s_cmd);
	free(f_cmd);
	free(s_cmd);
}

int main(int argc, char *argv[], char *envp[])
{
	t_files	files;

	if (argc != 5)
		exit(0);
	init(&files, argv, envp);
}