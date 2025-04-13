/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:39:54 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/13 13:39:54 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_chars(t_game *game)
{
	int	p_count;
	int	e_count;
	int	c_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	if (!check_chars_count(game, &p_count, &e_count, &c_count))
	{
		return (0);
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
	{
		if (p_count != 1)
			write(2, "Error: Invalid player count\n", 27);
		if (e_count != 1)
			write(2, "Error: Invalid exit count\n", 26);
		if (c_count < 1)
			write(2, "Error: Invalid collectible count\n", 34);
		return (0);
	}
	game->collectibles = c_count;
	return (1);
}

static int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->height - 1
				|| j == 0 || j == game->width - 1)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		if (j != game->width)
			return (0);
		i++;
	}
	return (1);
}

static int	is_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

int	has_valid_path(t_game *game)
{
	char	**map_copy;
	int		i;

	game->c_check = game->collectibles;
	game->e_check = 1;
	map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (0);
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	validate_map(game);
	move_on_paths(game->player_x, game->player_y, map_copy, game);
	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
	return (game->c_check == 0 && game->e_check == 0);
}

int	check_map(char *map_path, t_game *game)
{
	int		fd;
	char	*map_str;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	map_str = ft_strdup("");
	while (read_map_line(fd, &map_str))
		;
	close(fd);
	game->map = ft_split(map_str, '\n');
	free(map_str);
	if (!game->map)
		return (0);
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
	if (!is_rectangular(game) || !check_chars(game)
		|| !check_walls(game) || !has_valid_path(game))
	{
		cleanup(game);
		return (0);
	}
	return (1);
}
