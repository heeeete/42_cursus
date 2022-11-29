/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:17:37 by huipark           #+#    #+#             */
/*   Updated: 2022/11/26 16:51:48 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int main()
{
	void	*mlx;
	void	*mlx_win;

	// mlx_init(mlx, mlx_win);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "huipark");
	mlx_loop(mlx);
}