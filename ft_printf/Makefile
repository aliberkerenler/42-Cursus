NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
SRCS = ft_printf.c conversions/ft_print_char.c conversions/ft_print_string.c \
		conversions/ft_print_pointer.c conversions/ft_print_decimal.c \
		conversions/ft_print_unsigned.c conversions/ft_print_hex.c \
		conversions/ft_print_percent.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all