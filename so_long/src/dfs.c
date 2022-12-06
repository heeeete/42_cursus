/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:52:31 by huipark           #+#    #+#             */
/*   Updated: 2022/12/06 22:53:09 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	**copy_map(t_game game)
{
	int	**map_cp;
	int	i;
	int	j;

	i = 0;
	map_cp = (int **)wrap_malloc (sizeof(int *) * game.row_size);
	while (i < game.row_size)
	{
		j = 0;
		map_cp[i] = (int *)wrap_malloc(sizeof(int) * game.col_size);
		while (j < game.col_size)
			map_cp[i][j++] = 0;
		i++;
	}
	return (map_cp);
}

void	dfs(t_game *game, t_check *check, int x, int y)
{//                     위 아래 왼족 오른쪽
	const int	add_x[4] = {0, 0, -1, 1};
	const int	add_y[4] = {-1, 1, 0, 0};
	int			move_x;
	int			move_y;
	int			i;

	check->visited[y][x] = 1;
	i = 0;
	if (game->map[y][x] == 'C')
		check->item_count--;
	if (game->map[y][x] == 'E')
	{
		check->escape = 1;
		return ;
	}
	while (i < 4)
	{
		move_x = x + add_x[i];
		move_y = y + add_y[i];
		if (game->map[move_y][move_x] != '1' && !check->visited[move_y][move_x])
			dfs(game, check, move_x, move_y);
		i++;
	}
}

void	dfs_check(t_game game)
{
	t_check	check;
	int		i;

	i = 0;
	check.item_count = game.item_count;
	check.x = game.x;
	check.y = game.y;
	check.escape = 0;
	check.visited = copy_map(game);
	dfs(&game, &check, check.x, check.y);
	if (!check.escape || check.item_count)
		error("NOT VALID A MAP");
	while (i < game.row_size)
	{
		free (check.visited[i++]);
	}
	free (check.visited);
}