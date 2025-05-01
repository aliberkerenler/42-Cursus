NAME	= minitalk
SERVER	= server
CLIENT	= client
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) -o server server.c

$(CLIENT): client.c
	$(CC) $(CFLAGS) -o client client.c

clean:
	rm -f $(SERVER) $(CLIENT)

fclean: clean

re: fclean all