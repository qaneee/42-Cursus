#include "push_swap.h"

static void	down(t_stack **temp)
{
	t_stack	*head;

	head = *temp;
	while (head->next)
		head = head->next;
	push_front(temp, head->value, head->index);
	pop_back(temp);
}

void	rra(t_stack **a)
{
	if (!a || !*a)
		return ;
	down(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (!b || !*b)
		return ;
	down(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((!a || !*a) && (!b || !*b))
		return ;
	if (a && *a)
		down(a);
	if (b && *b)
		down(b);
	write(1, "rrr\n", 3);
}
