#include "push_swap_bonus.h"

static void	down_check(t_stack **temp)
{
	t_stack	*head;

	head = *temp;
	while (head->next)
		head = head->next;
	push_front(temp, head->value, head->index);
	pop_back(temp);
}

void	rra_check(t_stack **a)
{
	if (!a || !*a)
		return ;
	down_check(a);
}

void	rrb_check(t_stack **b)
{
	if (!b || !*b)
		return ;
	down_check(b);
}

void	rrr_check(t_stack **a, t_stack **b)
{
	if ((!a || !*a) && (!b || !*b))
		return ;
	if (a && *a)
		down_check(a);
	if (b && *b)
		down_check(b);
}