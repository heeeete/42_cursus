#include "../include/cub3d.h"

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
	while (game->map_info.map[len])
		++len;
	game->map_info.map_height = len - 6;
	free(save);

	////////////////////////////////////////////
	int i = 0;
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
	////////////////////////////////////////////
}

void find_player_direction(t_player *player, char c, int i, int j)
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

void parse_map(t_game *game)
{
	char **new_map;
	int i;
	int j;

	i = 6;
	j = 0;
	new_map = wrap_malloc(sizeof(char *) * (game->map_info.map_height + 1));
	while (game->map_info.map[i])
		new_map[j++] = ft_strdup(game->map_info.map[i++]);
	new_map[j] = NULL;
	i = 0;
	while (game->map_info.map[i])
		free(game->map_info.map[i++]);
	free(game->map_info.map);
	game->map_info.map = new_map;
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
				if (i == 0 || j == 0)
					error("Error : map is unvaild", NULL);
				else if (i == game->map_info.map_height || !map[i][j + 1])
					error("Error : map is unvaild", NULL);
				else if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
					error("Error : map is unvaild", NULL);
			}
			find_player_direction(player, map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void nullify_struct_members(t_game *game)
{
	game->img.NO = NULL;
	game->img.SO = NULL;
	game->img.WE = NULL;
	game->img.EA = NULL;
	game->img.F = NULL;
	game->img.C = NULL;
}

void check_texture_item(char *line, char *prefix, char **texture) {
    if (!ft_strncmp(line, prefix, ft_strlen(prefix))) {
        line += ft_strlen(prefix);
        while (*line == ' ')
            ++line;
        *texture = ft_strdup(line);
        if (open(*texture, O_RDONLY) < 0)
            error("Error : texture error", prefix);
    }
}

void check_texture(t_game *game, char *line)
{
	check_texture_item(line, "NO ", &(game->img.NO));
    check_texture_item(line, "SO ", &(game->img.SO));
    check_texture_item(line, "WE ", &(game->img.WE));
    check_texture_item(line, "EA ", &(game->img.EA));
	if (!ft_strncmp(line, "F ", 2)) {
		line += 2;
		while (*line == ' ')
			++line;
		game->img.F = ft_strdup(line);
	}
	if (!ft_strncmp(line, "C ", 2)) {
		line += 2;
		while (*line == ' ')
			++line;
		game->img.C = ft_strdup(line);
	}
}

void texture_parsing(t_game *game, char **map)
{
	int i;

	i = 0;
	nullify_struct_members(game);
	while (map[i])
		check_texture(game, map[i++]);
}

void init(t_game *game, char *argv)
{
	int fd;

	game->player.x = -1;
	game->player.y = -1;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error("Error : file open error", NULL);
	read_map(game, fd);
	texture_parsing(game, game->map_info.map);
	search_map(game, &game->player);
	printf("%s\n", game->img.NO);
	printf("%s\n", game->img.SO);
	printf("%s\n", game->img.EA);
	printf("%s\n", game->img.WE);
	printf("%s\n", game->img.F);
	printf("%s\n", game->img.C);
	printf("%c\n", game->player.player_direction);
}

int main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		exit(1);
	init(&game, argv[1]);
}
