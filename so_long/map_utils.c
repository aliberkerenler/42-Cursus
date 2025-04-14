/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:36:16 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/13 13:36:16 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars_count(t_game *game, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				(*p)++;
			else if (game->map[i][j] == 'E')
				(*e)++;
			else if (game->map[i][j] == 'C')
				(*c)++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
			{
				write(2, "Error: Invalid character in map\n", 33);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	move_on_paths(int x, int y, char **map, t_game *game)
{
	char	type;

	type = map[y][x];
	if (type == 'C')
	{
		game->c_check -= 1;
		map[y][x] = '1';
	}
	else if (type == 'E')
	{
		game->e_check -= 1;
		map[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map[y][x] = '1';
	else
		return ;
	move_on_paths(x + 1, y, map, game);
	move_on_paths(x - 1, y, map, game);
	move_on_paths(x, y + 1, map, game);
	move_on_paths(x, y - 1, map, game);
}

int	read_map_line(int fd, char **map_str)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		return (0);
	if (ft_strlen(line) == 1 && line[0] == '\n')
	{
		free(line);
		if (*map_str)
			free(*map_str);
		write(2, "Error: Empty line in map\n", 24);
		return (0);
	}
	if (!*map_str)
		*map_str = ft_strdup("");
	temp = *map_str;
	*map_str = ft_strjoin(*map_str, line);
	free(temp);
	free(line);
	return (1);
}
