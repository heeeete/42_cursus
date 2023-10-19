/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:56:32 by hyeslim           #+#    #+#             */
/*   Updated: 2023/01/22 11:10:10 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

t_cmd	*ready_to_run(char *str)
{
	t_cmd	*final;
	t_tok	*token;

	token = tokenize(str);
	final = chunk(&token);
	init_red(final);
	return (final);
}

void	argc_check(int argc, char *argv[], t_env *env, char *envp[])
{
	if (argc != 1)
	{
		printf("minihell: %s: no arguments required\n", argv[1]);
		exit (127);
	}
	init_env(env, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*str;
	t_cmd	*cmd;
	t_env	env;

	argc_check(argc, argv, &env, envp);
	while (1)
	{
		sig_status();
		str = readline("\033[0;35mminihell $> \033[0m");
		if (!str)
			break ;
		if (*str != '\0')
		{
			cmd = ready_to_run(str);
			if (cmd->next)
			{
				check_dollar(&env, cmd->next->tok);
				sig_init();
				run_cmd(cmd, env, envp);
			}
			free_cmd(cmd);
			add_history(str);
		}
		free(str);
	}
	int qweqwe=0;
}
