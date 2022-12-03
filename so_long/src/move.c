/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:12:11 by huipark           #+#    #+#             */
/*   Updated: 2022/12/03 21:53:34 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	press_key(int key_code, t_game *game, t_param *param)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game, param);
	if (key_code == KEY_A)
		move_a(game, param);
	if (key_code == KEY_S)
		move_s(game, param);
	if (key_code == KEY_D)
		move_d(game, param);
	return (0);
}

void	move_w(t_game *game, t_param *param)
{
	param->x++;
}
