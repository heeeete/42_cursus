/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:27:55 by huipark           #+#    #+#             */
/*   Updated: 2022/12/05 00:49:12 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*wrap_malloc(size_t s)
{
	void	*ret;

	ret = malloc(s);
	if (ret == NULL)
		error ("MALLOC ERROR");
	return (ret);
}

int	exit_game(t_game *game)
{
	printf("--------\nGAME END\n--------\n");
	// mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	succsess_game()
{
	printf("Congratulations! Success!\n");
	exit(0);
}