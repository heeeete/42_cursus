#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line.h"
#include "../mlx/mlx.h"
#include "../Libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_img
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
}				t_img;

typedef struct	s_map
{
	char	**map;
	int		map_height;
}				t_map;

typedef struct s_playsr
{
	int		x;
	int		y;
	char	player_direction;
}				t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map_info;
	t_player	player;
}				t_game;

void	error(char *msg, char *msg2);
void	*wrap_malloc(size_t s);

#endif
