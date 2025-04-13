/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:35:19 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/13 13:35:19 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, exit_on_close, game);
}

int	exit_on_close(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

static int	checker_file(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
			break ;
		i++;
	}
	if (filename[i] == '\0')
		return (0);
	if (ft_strncmp(&filename[i], ".ber", 4) != 0)
		return (0);
	return (1);
		
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long map.ber\n", 31);
		return (1);
	}
		if (!checker_file(argv[1]))
	{
		write(2, "Error: Invalid file extention\n", 30);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!check_map(argv[1], &game))
	{
		write(2, "Error: Invalid map\n", 18);
		return (1);
	}
	init_game(&game);
	load_images(&game);
	render_map(&game);
	init_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
