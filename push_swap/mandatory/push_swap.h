#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int								value;
	int								index;
	struct s_stack					*next;
}	t_stack;

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push_front(t_stack **lst, int val, int ind);
void	push_back(t_stack **lst, int val, int ind);
void	pop_front(t_stack **lst);
void	pop_back(t_stack **lst);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
int		stack_size(t_stack *a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	free_stack(t_stack **lst);
char	**free_split(char **split, int i);
void	index_sort(t_stack **a);
void	sort_type(t_stack **a, t_stack **b, int size);
void	chunk_sort(t_stack **a, t_stack **b);
void	ft_swap(int *var1, int *var2);
int		is_sorted(t_stack *lst);
int		validate_args(int argc, char **argv, t_stack **stack);

#endif
