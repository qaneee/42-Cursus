#include "push_swap.h"

static void	swap_stack(t_stack **tmp)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!tmp || !*tmp || !(*tmp)->next)
		return ;
	first_node = *tmp;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*tmp = second_node;
}

void	sa(t_stack **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
