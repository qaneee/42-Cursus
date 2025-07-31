CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft -Iminilibx-linux

SRC_FOLDER = srcs
OBJ_FOLDER = objs

SRC = $(SRC_FOLDER)/fdf.c \
      $(SRC_FOLDER)/atoi_hex.c \
      $(SRC_FOLDER)/bresenham.c \
      $(SRC_FOLDER)/color.c \
      $(SRC_FOLDER)/draw.c \
      $(SRC_FOLDER)/fill_matrix.c \
      $(SRC_FOLDER)/free_func.c \
      $(SRC_FOLDER)/handle_colors.c \
      $(SRC_FOLDER)/handle_errors.c \
      $(SRC_FOLDER)/handle_hooks.c \
      $(SRC_FOLDER)/hooks.c \
      $(SRC_FOLDER)/key_hooks.c \
      $(SRC_FOLDER)/projections.c \
      $(SRC_FOLDER)/rotation.c \
      $(SRC_FOLDER)/map_dimension.c 

OBJS = $(SRC:$(SRC_FOLDER)/%.c=$(OBJ_FOLDER)/%.o)
LIBFT = libft/libft.a
NAME = fdf

all: $(NAME)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

clean:
	rm -rf $(OBJ_FOLDER)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re