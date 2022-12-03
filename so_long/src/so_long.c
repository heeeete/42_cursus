/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:17:37 by huipark           #+#    #+#             */
/*   Updated: 2022/12/03 21:41:54 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	img_init(t_game game)
{
	void	*makima;
	void	*map;
	int		widht;
	int		height;

	makima = mlx_xpm_file_to_image(game.mlx, "./image/pochita.xpm", &widht, &height);
	map = mlx_xpm_file_to_image(game.mlx, "./image/map.xpm", &widht, &height);
	mlx_put_image_to_window(game.mlx, game.win, map, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, makima, 0, 0);
}

int				key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

int main(int argc, char *argv[])
{
	t_game	game;
	t_param	param;

	if (argc != 2)
		error("CHECK ARGC");
	init(&game, &param, argv[1]);
	game.win = mlx_new_window(game.mlx, game.col_size * IMG_SIZE, game.row_size * IMG_SIZE, "huipark");
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &press_key, &param);
	img_init(game);
	mlx_loop(game.mlx);
}