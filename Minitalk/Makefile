CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = printf
INCLUDES = -I. -I$(PRINTF_DIR)

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_DIR = obj
OBJ_CLIENT = $(SRC_CLIENT:%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER = $(SRC_SERVER:%.c=$(OBJ_DIR)/%.o)

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(CLIENT) $(SERVER)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(CLIENT): $(OBJ_CLIENT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF_LIB) -o $@

$(SERVER): $(OBJ_SERVER) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF_LIB) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
