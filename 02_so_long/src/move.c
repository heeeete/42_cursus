/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:12:11 by huipark           #+#    #+#             */
/*   Updated: 2022/12/09 17:13:24 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_s(t_game *game)
{
	t_player	player;

	player = current_location_player(*game);
	if (player.down == '1')
		return ;
	else if (player.down == '0' || player.down == 'C')
	{
		if (player.down == 'C')
		{
			game->item_count--;
			draw(game, "./image/map.xpm", player.row + 1, player.col);
		}
		draw(game, "./image/map.xpm", player.row, player.col);
		draw(game, "./image/pochita.xpm", player.row + 1, player.col);
		game->map[player.row][player.col] = '0';
		game->map[player.row + 1][player.col] = 'P';
		printf("MOVEMENT : %d\n", ++game->move_count);
	}
	else if (player.down == 'E' && game->item_count == 0)
	{
		printf("MOVEMENT : %d\n", ++game->move_count);
		succsess_game();
	}
}

void	move_w(t_game *game)
{
	t_player	player;

	player = current_location_player(*game);
	if (player.up == '1')
		return ;
	else if (player.up == '0' || player.up == 'C')
	{
		if (player.up == 'C')
		{
			game->item_count--;
			draw(game, "./image/map.xpm", player.row - 1, player.col);
		}
		draw(game, "./image/map.xpm", player.row, player.col);
		draw(game, "./image/pochita.xpm", player.row - 1, player.col);
		game->map[player.row][player.col] = '0';
		game->map[player.row - 1][player.col] = 'P';
		printf("MOVEMENT : %d\n", ++game->move_count);
	}
	else if (player.up == 'E' && game->item_count == 0)
	{
		printf("MOVEMENT : %d\n", ++game->move_count);
		succsess_game();
	}
}

void	move_a(t_game *game)
{
	t_player	player;

	player = current_location_player(*game);
	if (player.left == '1')
		return ;
	else if (player.left == '0' || player.left == 'C')
	{
		if (player.left == 'C')
		{
			game->item_count--;
			draw(game, "./image/map.xpm", player.row, player.col - 1);
		}
		draw(game, "./image/map.xpm", player.row, player.col);
		draw(game, "./image/pochita_left.xpm", player.row, player.col - 1);
		game->map[player.row][player.col] = '0';
		game->map[player.row][player.col - 1] = 'P';
		printf("MOVEMENT : %d\n", ++game->move_count);
	}
	else if (player.left == 'E' && game->item_count == 0)
	{
		printf("MOVEMENT : %d\n", ++game->move_count);
		succsess_game();
	}
}

void	move_d(t_game *game)
{
	t_player	player;

	player = current_location_player(*game);
	if (player.right == '1')
		return ;
	else if (player.right == '0' || player.right == 'C')
	{
		if (player.right == 'C')
		{
			game->item_count--;
			draw(game, "./image/map.xpm", player.row, player.col + 1);
		}
		draw(game, "./image/map.xpm", player.row, player.col);
		draw(game, "./image/pochita_right.xpm", player.row, player.col + 1);
		game->map[player.row][player.col] = '0';
		game->map[player.row][player.col + 1] = 'P';
		printf("MOVEMENT : %d\n", ++game->move_count);
	}
	else if (player.right == 'E' && game->item_count == 0)
	{
		printf("MOVEMENT : %d\n", ++game->move_count);
		succsess_game();
	}
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game();
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}
