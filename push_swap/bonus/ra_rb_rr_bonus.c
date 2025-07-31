#include "push_swap_bonus.h"

static void	up_check(t_stack **temp)
{
	push_back(temp, (*temp)->value, (*temp)->index);
	pop_front(temp);
}

void	ra_check(t_stack **a)
{
	if (!a || !*a)
		return ;
	up_check(a);
}

void	rb_check(t_stack **b)
{
	if (!b || !*b)
		return ;
	up_check(b);
}

void	rr_check(t_stack **a, t_stack **b)
{
	if ((!a || !*a) && (!b || !*b))
		return ;
	if (a && *a)
		up_check(a);
	if (b && *b)
		up_check(b);
}
