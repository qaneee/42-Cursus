#include "push_swap_bonus.h"

void	pa_check(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		return ;
	push_front(a, (*b)->value, (*b)->index);
	pop_front(b);
}

void	pb_check(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	push_front(b, (*a)->value, (*a)->index);
	pop_front(a);
}
