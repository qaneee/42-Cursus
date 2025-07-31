#include "push_swap_bonus.h"

static void	swap_stack_check(t_stack **tmp)
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

void	sa_check(t_stack **a)
{
	swap_stack_check(a);
}

void	sb_check(t_stack **b)
{
	swap_stack_check(b);
}

void	ss_check(t_stack **a, t_stack **b)
{
	swap_stack_check(a);
	swap_stack_check(b);
}
