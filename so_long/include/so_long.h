/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:09:47 by huipark           #+#    #+#             */
/*   Updated: 2022/12/03 21:43:49 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_opengl/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define IMG_SIZE					64
# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

typedef struct s_game{
	void	*mlx;
	void	*win;
	char	**map;
	int		col_size;
	int		row_size;
}				t_game;

void	init(t_game *game, t_param *param, char *map_name);
void	*wrap_malloc(size_t s);
char	**ft_split(char const *s, char c);
void	error(char *msg);
void	map_check(t_game game);
void	exit_game(t_game *game);
int		press_key(int key_code, t_game *game, t_param *param);

#endif