NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx -I./libft -g
MLX = -L./minilibx -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT = -L./libft -lft

SRCS = check_map.c game_render.c game_utils.c get_next_line.c \
		map_utils.c player_moves.c so_long.c
OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft 