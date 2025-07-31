#include "push_swap.h"

static void	up(t_stack **temp)
{
	push_back(temp, (*temp)->value, (*temp)->index);
	pop_front(temp);
}

void	ra(t_stack **a)
{
	if (!a || !*a)
		return ;
	up(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (!b || !*b)
		return ;
	up(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if ((!a || !*a) && (!b || !*b))
		return ;
	if (a && *a)
		up(a);
	if (b && *b)
		up(b);
	write(1, "rr\n", 3);
}
