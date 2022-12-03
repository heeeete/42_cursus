/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:13:35 by huipark           #+#    #+#             */
/*   Updated: 2022/12/03 21:41:27 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	size_check_map(t_game *game)
{
	int temp_cor_count;
	int	cor_count;
	int row_count;

	row_count = 0;
	temp_cor_count = 0;
	while (game->map[0][temp_cor_count])
		temp_cor_count++;
	while (game->map[row_count])
	{
		cor_count = 0;
		while (game->map[row_count][cor_count])
			cor_count++;
		if (temp_cor_count != cor_count)
			error("MAP IS NOT RECTANGLE");
		row_count++;
	}
	game->row_size = row_count;
	game->col_size = cor_count;
}

void	read_map(t_game *game, int fd)
{
	char	*line;
	char	*save;
	char	*temp_address;

	line = get_next_line(fd);
	if (!line)
		error("EMPTY MAP");
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


void			param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

void	init(t_game *game, t_param *param, char *map_name)
{
	game->mlx = mlx_init();
	param_init(param);
	check_fd(game, map_name);
	size_check_map(game);
	map_check(*game);
}