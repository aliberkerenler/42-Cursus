/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:37:26 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/13 13:37:26 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *game)
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
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	game->moves = 0;
	validate_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		cleanup(game);
		exit(0);
	}
	else if (keycode == 65362 || keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 65364 || keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 65361 || keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 65363 || keycode == 100)
		move_player(game, 1, 0);
	return (0);
}
