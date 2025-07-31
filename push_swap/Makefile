NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I.

MANDATORY_SRCS	= mandatory/chunk_sort.c \
				  mandatory/free_funcs.c \
				  mandatory/handle_pa_pb.c \
				  mandatory/handle_ra_rb_rr.c \
				  mandatory/handle_rra_rrb_rrr.c \
				  mandatory/handle_sa_sb_ss.c \
				  mandatory/push_and_pop.c \
				  mandatory/sorting_funds.c \
				  mandatory/sorting.c \
				  mandatory/utils.c \
				  mandatory/validation.c \
				  mandatory/main.c \

BONUS_SRCS		= bonus/check_input_bonus.c \
				  bonus/pa_pb_bonus.c \
				  bonus/ra_rb_rr_bonus.c \
				  bonus/rra_rrb_rrr_bonus.c \
				  bonus/sa_sb_ss_bonus.c \
				  bonus/validation_bonus.c \
				  bonus/main_bonus.c \

MANDATORY_OBJS	= $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)


MANDATORY_OBJS_NO_MAIN = $(filter-out mandatory/main.o, $(MANDATORY_OBJS))

HEADER			= mandatory/push_swap.h
BONUS_HEADER	= bonus/push_swap_bonus.h

LIBFT			= libft/libft.a

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(MANDATORY_OBJS_NO_MAIN) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(LIBFT):
	make -C libft


mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus/%.o: bonus/%.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re