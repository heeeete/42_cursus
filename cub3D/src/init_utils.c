/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:13:36 by huipark           #+#    #+#             */
/*   Updated: 2023/06/16 20:04:51 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_rgb(char *rgb_str){
	int		cnt;

	if (!rgb_str)
		error("invaild file", NULL);
	cnt = 0;
	while (*rgb_str)
	{
		while (*rgb_str == ' ')
			++rgb_str;
		if (*rgb_str == ',')
			++cnt;
		else if ((*rgb_str == 0 && cnt != 2) || *rgb_str == 0)
			error("RGB_Error : invaild rgb", NULL);
		else if (ft_isdigit(*rgb_str) && *(rgb_str + 1) == ' ')
		{
			++rgb_str;
			while (*rgb_str == ' ')
				++rgb_str;
			if (*rgb_str == ',')
				++cnt;
			else if (!ft_isdigit(*rgb_str))
				error("RGB_Error : rgb has to have only number", NULL);
		}
		else if (!ft_isdigit(*rgb_str) && *rgb_str != ' ')
				error("RGB_Error : rgb has to have only number", NULL);
		if (cnt > 2)
			error("RGB_Error : too many ','", NULL);
		if (*rgb_str != 0)
			++rgb_str;
	}
}

int	set_rgb(char *rgb_str, int flag) {
	char	*rgb;
	int		ret;

	if (flag == 0)
		rgb = ft_strtok(rgb_str, ",");
	else
		rgb = ft_strtok(NULL, ",");
	if (!rgb)
		error("RGB_Error : There should be 3 numbers", NULL);
	ret = ft_atoi(rgb);
	if (ret < 0 || ret > 255)
		error("RGB Error : ranges from 0 to 255", NULL);
	return ret;
}

void read_map(t_game *game, int fd)
{
	char	*line;
	char	*save;
	char	*temp_address;
	int		len;

	len = 0;
	line = get_next_line(fd);
	if (!line)
		error("EMPTY MAP", NULL);
	save = ft_strdup("");
	while (line)
	{
		temp_address = save;
		save = ft_strjoin(save, line);
		free(temp_address);
		free(line);
		line = get_next_line(fd);
	}
	game->map_info.map = ft_split(save, '\n');

	/////////////////////////////////////////////////////////////////
	int i = 0;
	printf("*****************파일 내용******************\n");
	while (game->map_info.map[i])
	{
		int j = 0;
		while (game->map_info.map[i][j])
		{
			printf("%c", game->map_info.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n\n");
	/////////////////////////////////////////////////////////////////
	while (game->map_info.map[len])
		++len;
	game->map_info.map_height = len - 6;
	free(save);
}

static void find_player_direction(t_player *player, char c, int i, int j)
{
	if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
	{
		if (player->x != -1 && player->y != -1)
			error("Error : There must be only one player", NULL);
		player->x = j;
		player->y = i;
		player->player_direction = c;
	}
}

void search_map(t_game *game, t_player *player)
{
	int i;
	int j;
	char **map;

	i = 0;
	parse_map(game);
	map = game->map_info.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == game->map_info.map_height \
				|| !map[i][j + 1] || map[i][j - 1] == ' ' || map[i][j + 1] == ' ' \
				|| map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
					error("Error : map is unvaild", NULL);
				// else if (i == game->map_info.map_height || !map[i][j + 1])
				// 	error("Error : map is unvaild", NULL);
				// else if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
				// 	error("Error : map is unvaild", NULL);
			}
			else if (map[i][j] != '1' && map[i][j] != 'N' && map[i][j] != 'S' \
			&& map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != ' ')
				error("MAP Error", NULL);
			find_player_direction(player, map[i][j], i, j);
			j++;
		}
		i++;
	}
}
