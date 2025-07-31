CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = printf
INCLUDES = -I. -I$(PRINTF_DIR)

SRC_CLIENT = client.c
SRC_SERVER = server.c
PRINTF_SRCS = $(wildcard $(PRINTF_DIR)/ft_*.c)

OBJ_DIR = obj
OBJ_CLIENT = $(SRC_CLIENT:%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER = $(SRC_SERVER:%.c=$(OBJ_DIR)/%.o)
OBJ_PRINTF = $(PRINTF_SRCS:$(PRINTF_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(OBJ_PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(OBJ_SERVER) $(OBJ_PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re