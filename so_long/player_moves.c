/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:35:29 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/13 13:35:29 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(t_game *game)
{
	write(1, "Moves: ", 7);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
}

static int	is_valid_move(t_game *game, char next_tile)
{
	if (next_tile == '1')
		return (0);
	if (next_tile == 'E' && game->collectibles != 0)
		return (0);
	return (1);
}

static void	handle_collectible(t_game *game, char next_tile)
{
	if (next_tile == 'C')
		game->collectibles--;
}

static void	handle_exit(t_game *game, char next_tile)
{
	if (next_tile == 'E' && game->collectibles == 0)
	{
		write(1, "You won!\n", 9);
		cleanup(game);
		exit(0);
	}
}

void	move_player(t_game *game, int x, int y)
{
	char	next_tile;

	next_tile = game->map[game->player_y + y][game->player_x + x];
	if (!is_valid_move(game, next_tile))
		return ;
	handle_collectible(game, next_tile);
	handle_exit(game, next_tile);
	game->map[game->player_y][game->player_x] = '0';
	game->player_x += x;
	game->player_y += y;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	print_moves(game);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}
