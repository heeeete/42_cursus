/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:09:47 by huipark           #+#    #+#             */
/*   Updated: 2022/12/09 17:12:55 by huipark          ###   ########.fr       */
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
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_check{
	int	**visited;
	int	x;
	int	y;
	int	item_count;
	int	escape;
}				t_check;

typedef struct s_game{
	void	*mlx;
	void	*win;
	void	*pochita;
	char	**map;
	int		col_size;
	int		row_size;
	int		move_count;
	int		item_count;
	int		x;
	int		y;
	int		main_charecter_flag;
}				t_game;

typedef struct s_player{
	char	left;
	char	right;
	char	up;
	char	down;
	int		row;
	int		col;
}				t_player;

void		init(t_game *game, char *map_name);
void		*wrap_malloc(size_t s);
char		**ft_split(char const *s, char c);
void		error(char *msg);
int			exit_game(void);
int			press_key(int key_code, t_game *game);
t_player	current_location_player(t_game game);
void		draw(t_game *game, char *img_dir, int row, int col);
void		succsess_game(void);
void		dfs_check(t_game game);

#endif