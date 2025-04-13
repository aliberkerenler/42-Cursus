/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:48:00 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/13 13:48:00 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		c_check;
	int		e_check;
	int		moves;
	void	*floor_img;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
}	t_game;

int		check_map(char *map_path, t_game *game);
int		exit_on_close(t_game *game);
int		check_chars_count(t_game *game, int *p, int *e, int *c);
int		handle_key(int keycode, t_game *game);
int		read_map_line(int fd, char **map_str);
int		check_chars_count(t_game *game, int *p, int *e, int *c);
int		validate_map(t_game *game);

void	init_game(t_game *game);
void	move_player(t_game *game, int x, int y);
void	load_images(t_game *game);
void	render_map(t_game *game);
void	cleanup(t_game *game);
void	move_on_paths(int x, int y, char **map, t_game *game);

char	*get_next_line(int fd);

#endif