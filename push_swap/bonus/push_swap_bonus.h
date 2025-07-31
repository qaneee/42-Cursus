#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../mandatory/push_swap.h"
# include <stdlib.h>
# include <unistd.h>

void	read_input(t_stack **a, t_stack **b);
void	pa_check(t_stack **a, t_stack **b);
void	pb_check(t_stack **a, t_stack **b);
void	sa_check(t_stack **a);
void	sb_check(t_stack **b);
void	ss_check(t_stack **a, t_stack **b);
void	ra_check(t_stack **a);
void	rb_check(t_stack **b);
void	rr_check(t_stack **a, t_stack **b);
void	rra_check(t_stack **a);
void	rrb_check(t_stack **b);
void	rrr_check(t_stack **a, t_stack **b);
int	validate_args_b(int argc, char **argv, t_stack **stack);

#endif