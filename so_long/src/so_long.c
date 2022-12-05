/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:17:37 by huipark           #+#    #+#             */
/*   Updated: 2022/12/05 19:34:54 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_player	current_location_player(t_game game)
{
	t_player	player;
	int			i;
	int			j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j] != 'P' && game.map[i][j])
			j++;
		if (game.map[i][j] == 'P')
		{
			break ;
		}
		i++;
	}
	player.left = game.map[i][j - 1];
	player.right = game.map[i][j + 1];
	player.up = game.map[i - 1][j];
	player.down = game.map[i + 1][j];
	player.row = i;
	player.col = j;
	return (player);
}

void	draw(t_game *game, char *img_dir, int row, int col)
{
	void	*img;
	int		widht;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, img_dir, &widht, &height);
	if (!img)
		error ("IMG LOAD ERROR");
	mlx_put_image_to_window(game->mlx, game->win, img,
		IMG_SIZE * col, IMG_SIZE * row);
}

void	check_elemnet(t_game *game, int row, int col)
{
	char	element;

	element = game->map[row][col];
	if (element == '1')
		draw(game, "./image/brick.xpm", row, col);
	else if (element == '0')
		draw(game, "./image/map.xpm", row, col);
	else if (element == 'P')
		draw(game, "./image/pochita.xpm", row, col);
	else if (element == 'C')
	{
	game->item_count++;
		draw(game, "./image/item.xpm", row, col);
	}
	else if (element == 'E')
	{
		draw(game, "./image/map.xpm", row, col);
		draw(game, "./image/escape.xpm", row, col);
	}
}

void	draw_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row_size)
	{
		j = 0;
		while (j < game->col_size)
		{
			check_elemnet(game, i, j);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		error("CHECK ARGC");
	init(&game, argv[1]);
	draw_image(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx);
}
