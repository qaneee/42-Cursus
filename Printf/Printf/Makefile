# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arvardan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 12:20:04 by arvardan          #+#    #+#              #
#    Updated: 2025/02/11 12:20:55 by arvardan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBC = ar rcs
NAME = libftprintf.a

SRCS = ft_print_char.c ft_print_string.c ft_print_num.c \
       ft_print_ptr.c  ft_print_percent.c ft_print_hexlower.c \
       ft_print_hexupper.c ft_printf.c ft_print_unsigned.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
