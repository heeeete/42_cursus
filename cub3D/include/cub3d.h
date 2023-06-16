#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line.h"
#include "../mlx/mlx.h"
#include "../Libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define SIZE 64

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;

	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
}				t_img;

typedef struct	s_frgb
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}				t_frgb;

typedef struct	s_crgb
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}				t_crgb;

typedef struct	s_map
{
	char	**map;
	int		map_height;
	int		max_width;
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
	t_frgb		f_rgb;
	t_crgb		c_rgb;
}				t_game;

void	error(char *msg, char *msg2);
void	*wrap_malloc(size_t s);

//parse.c
void	check_texture(t_game *game, char *line);
void	texture_parsing(t_game *game, char **map);
void	 parse_map(t_game *game);

//init.c
void nullify_struct_members(t_game *game);
void init(t_game *game, char *argv);
void init_rgb(t_game *game);

//init_utils.c
void read_map(t_game *game, int fd);
int	set_rgb(char *rgb_str, int flag);
void	check_rgb(char *rgb_str);
void search_map(t_game *game, t_player *player);

#endif
