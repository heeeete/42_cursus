/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:18:36 by huipark           #+#    #+#             */
/*   Updated: 2023/06/17 17:07:33 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int absolute_value(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}


void draw_rectangle(t_game *game, int x, int y, int color)
{
    int i;
    int j;

    y *= SIZE;
    x *= SIZE;
    i = 0;
    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE)
        {
            int pixel_index = (y + i) * (game->map_info.max_width * SIZE) + (x + j);
            if (game->map_info.map[y / SIZE][x / SIZE] == 'N')
            {
                if (i == SIZE / 2 && j == SIZE / 2)
                    game->img.data[pixel_index] = 0xFF0000; // 빨간색 점
                else
                    game->img.data[pixel_index] = 0xFFFFFF; // 흰색
            }
            else
            {
                game->img.data[pixel_index] = color;
            }
            j++;
        }
        i++;
    }
}

void draw_rectangles(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_info.map_height)
    {
        j = 0;
        while (game->map_info.map[i][j])
        {
            int color;
            if (game->map_info.map[i][j] == '1')
                color = 0x000000; // 벽의 색상
            else
                color = 0xFFFFFF; // 빈 공간의 색상
            draw_rectangle(game, j, i, color);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void draw_rectangles2(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_info.map_height)
    {
        j = 0;
        while (game->map_info.map[i][j])
        {
            int color;
            if (game->map_info.map[i][j] == '1')
                color = 0x000000; // 벽의 색상
            else
                color = 0xFFFFFF; // 빈 공간의 색상
            draw_rectangle(game, j, i, color);
            j++;
        }
        i++;
    }
}

int key_press(int key)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == X_EVENT_KEY_PRESS)
		exit(0);
	return (0);
}

int main_loop(t_game game)
{
	// draw_rectangles2(&game);
	return (0);
}

int main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		exit(1);
	init(&game, argv[1]);
	////////////////////////////////////////////
	printf("*****************파싱 결과*************\n\n");
	int i = 0;
	while (game.map_info.map[i])
	{
		int j = 0;
		while (game.map_info.map[i][j])
		{
			printf("%c", game.map_info.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("FILE PATH : %s\n", game.img.NO);
	printf("FILE PATH : %s\n", game.img.SO);
	printf("FILE PATH : %s\n", game.img.EA);
	printf("FILE PATH : %s\n", game.img.WE);
	printf("F_RGB : %d\n", game.f_rgb.r);
	printf("F_RGB : %d\n", game.f_rgb.g);
	printf("F_RGB : %d\n", game.f_rgb.b);
	printf("C_RGB : %d\n", game.c_rgb.r);
	printf("C_RGB : %d\n", game.c_rgb.g);
	printf("C_RGB : %d\n", game.c_rgb.b);
	printf("PLAYER DIRECTION : %c\n\n", game.player.player_direction);
	printf("*****************************************\n");
	////////////////////////////////////////////
	draw_rectangles(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, NULL);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	// mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);
	mlx_loop(game.mlx);
	// system("leaks cub3D");

}
