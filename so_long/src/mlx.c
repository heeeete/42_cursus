/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:08:32 by huipark           #+#    #+#             */
/*   Updated: 2022/11/25 20:22:48 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_start(void *mlx, void *mlx_win)
{
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "HUIPARK");
	mlx_loop(mlx);
}
