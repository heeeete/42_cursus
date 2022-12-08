/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:13:35 by huipark           #+#    #+#             */
/*   Updated: 2022/12/08 21:51:49 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_check(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[0][j] != '1' || game.map[game.row_size - 1][j] != '1'
				|| game.map[i][0] != '1'
				|| game.map[i][game.col_size - 1] != '1')
				error("NOT VALID A MAP");
			if (game.map[i][j] != '0' && game.map[i][j] != '1'
				&& game.map[i][j] != 'C' && game.map[i][j] != 'E'
				&& game.map[i][j] != 'P')
				error("NOT VALID A MAP");
			j++;
		}
		i++;
	}
}

void	size_check_map(t_game *game)
{
	int	temp_cor_count;
	int	col_count;
	int	row_count;

	row_count = 0;
	temp_cor_count = 0;
	while (game->map[0][temp_cor_count])
		temp_cor_count++;
	while (game->map[row_count])
	{
		col_count = 0;
		while (game->map[row_count][col_count])
			col_count++;
		if (temp_cor_count != col_count)
			error("MAP IS NOT RECTANGLE");
		row_count++;
	}
	game->row_size = row_count;
	game->col_size = col_count;
}

void	read_map(t_game *game, int fd)
{
	char	*line;
	char	*save;
	char	*temp_address;

	line = get_next_line(fd);
	if (!line)
		error("EMPTY MAP");
	save = ft_strdup("");
	while (line)
	{
		temp_address = save;
		save = ft_strjoin(save, line);
		free(temp_address);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(save, '\n');
	free(save);
}

void	check_fd(t_game *game, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error("FILE OPEN ERROR");
	read_map(game, fd);
}

void	init(t_game *game, char *map_name)
{
	game->move_count = 0;
	game->item_count = 0;
	game->main_charecter_flag = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		error("MLX INIT ERROR");
	check_fd(game, map_name);
	size_check_map(game);
	game->win = mlx_new_window(game->mlx, game->col_size * IMG_SIZE,
			game->row_size * IMG_SIZE, "huipark");
	if (!game->win)
		error("MLX WINDOW OPEN ERROR");
	map_check(*game);
}
