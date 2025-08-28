# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 01:18:44 by arvardan          #+#    #+#              #
#    Updated: 2025/08/28 12:20:33 by ipogodae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

CFLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG),debug)
CFLAGS += -g3
endif

ifeq ($(DEBUG),full)
CFLAGS += -g3 -fsanitize=address -fno-omit-frame-pointer
endif

INCLUDES = -Iincludes -Ilibft
LDFLAGS = -Llibft -lft -lreadline -lhistory -lncurses

ifeq ($(UNAME), Darwin)
	INCLUDES += -I/usr/local/opt/readline/include
	LDFLAGS += -L/usr/local/opt/readline/lib
endif

SRC_FOLDER = srcs/
OBJ_FOLDER = objs/
INC_FOLDER = includes/

INCS = $(addprefix $(INC_FOLDER), \
	commands.h \
	minishell.h \
	signals.h \
	structs.h \
	execute.h \
	builtins.h \
	path.h \
	environment.h \
)

SRCS = $(addprefix $(SRC_FOLDER), \
	main.c \
	signals/signal.c \
	lexical_analyzer/char_vector.c \
	lexical_analyzer/line_to_tokens.c \
	lexical_analyzer/parse_state_utils.c \
	lexical_analyzer/token_processing.c \
	lexical_analyzer/token_utils.c \
	lexical_analyzer/token_vector.c \
	token_analyzer/command_utils.c \
	token_analyzer/command_additional_utils.c \
	token_analyzer/command_vector.c \
	token_analyzer/tokens_to_commands.c \
	token_analyzer/tokens_to_commands2.c \
	token_analyzer/process_fields.c \
	builtins/pwd.c \
	builtins/echo.c \
	builtins/cd.c \
	builtins/env.c \
	builtins/unset.c \
	builtins/export.c \
	builtins/builtin_util.c \
	builtins/exit.c \
	errors.c \
	path.c \
	string.c \
	execution/execute_cmd.c \
	execution/externals.c \
	execution/exec_helper.c \
	execution/execute_commands.c \
	execution/builtin_redirs.c \
	redirs/redirection_type.c \
	redirs/redir_utils.c \
	redirs/heredoc.c \
	environment/init_environment.c \
	environment/env_actions.c \
	environment/convert_to_arr.c \
	environment/pwd_oldpwd_var.c \
	environment/shlvl.c \
)

OBJS = $(SRCS:$(SRC_FOLDER)%.c=$(OBJ_FOLDER)%.o)
LIBFT = libft/libft.a

NAME = minishell

all: $(NAME)

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_FOLDER)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
