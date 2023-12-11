CLIENT_NAME = client
SERVER_NAME = server

CFLAGS = -Wall -Werror -Wextra

#Mandatory
CLIENT = ./src/client.c
SERVER = ./src/server.c

CLIENT_OBJ = $(CLIENT:%.c=%.o)
SERVER_OBJ = $(SERVER:%.c=%.o)

#Bonus
CLIENT_BONUS = ./src/client_bonus.c
SERVER_BONUS = ./src/server_bonus.c

CLIENT_BONUS_OBJ = $(CLIENT_BONUS:%.c=%.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS:%.c=%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(LIBFT) client_bonus server_bonus

$(LIBFT):
	@cd $(LIBFT_PATH) && $(MAKE)

$(CLIENT_NAME): $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)

client_bonus: $(CLIENT_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT) -o $(CLIENT_NAME)

server_bonus: $(SERVER_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT) -o $(SERVER_NAME)

clean:
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)
	@$(RM) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	@cd $(LIBFT_PATH) && $(MAKE) clean

fclean: clean
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@cd $(LIBFT_PATH) && $(MAKE) fclean
	
re: fclean all

.PHONY: all clean fclean re bonus