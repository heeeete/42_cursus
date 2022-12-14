/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:17:37 by huipark           #+#    #+#             */
/*   Updated: 2022/11/25 20:39:08 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
	void	*mlx;
	void	*mlx_win;

	// mlx_init(mlx, mlx_win);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "huipark");
	mlx_loop(mlx);
}