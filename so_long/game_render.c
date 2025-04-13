/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:46:35 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/13 13:46:35 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
}

static void	put_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img,
			j * TILE_SIZE, i * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_image(game, i, j);
			j++;
		}
		i++;
	}
}

void	cleanup(t_game *game)
{
	int	i;

	i = 0;
	while (game->map && game->map[i])
		free(game->map[i++]);
	free(game->map);
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->wall_img)
			mlx_destroy_image(game->mlx, game->wall_img);
		if (game->player_img)
			mlx_destroy_image(game->mlx, game->player_img);
		if (game->collectible_img)
			mlx_destroy_image(game->mlx, game->collectible_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx, game->exit_img);
		if (game->floor_img)
			mlx_destroy_image(game->mlx, game->floor_img);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
