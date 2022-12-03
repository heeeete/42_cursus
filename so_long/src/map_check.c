/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:57:15 by huipark           #+#    #+#             */
/*   Updated: 2022/12/03 21:08:57 by huipark          ###   ########.fr       */
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
			if (game.map[i][j] != '0' && game.map[i][j] != '1'
				&& game.map[i][j] != 'C' && game.map[i][j] != 'E'
				&& game.map[i][j] != 'P')
				error("NOT VALID A MAP");
			j++;
		}
		i++;
	}
}