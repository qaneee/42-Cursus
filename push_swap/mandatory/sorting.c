#include "push_swap.h"

static void	sort_3(t_stack **a)
{
	int	i;
	int	j;
	int	k;

	if (!a || !*a || stack_size(*a) != 3)
		return ;
	i = (*a)->index;
	j = (*a)->next->index;
	k = (*a)->next->next->index;
	if (i < j && i < k && j > k)
	{
		sa(a);
		ra(a);
	}
	else if (k > j && k > i && i > j)
		sa(a);
	else if (j > k && j > i && i > k)
		rra(a);
	else if (i > j && j < k && i > k)
		ra(a);
	else if (i > j && j > k && i > k)
	{
		sa(a);
		rra(a);
	}
}

static int	min_index(t_stack *a)
{
	int	min;

	if (!a)
		return (-1);
	min = a->index;
	while (a)
	{
		if (a->index < min)
			min = a->index;
		a = a->next;
	}
	return (min);
}

static int	index_position(t_stack *a, int idx)
{
	int	position;

	if (!a)
		return (-1);
	position = 0;
	while (a)
	{
		if (a->index == idx)
			return (position);
		a = a->next;
		position++;
	}
	return (-1);
}

static void	sort_5(t_stack **a, t_stack **b, int size)
{
	int	min_idx;
	int	position;

	while (size > 3)
	{
		min_idx = min_index(*a);
		position = index_position(*a, min_idx);
		if (position == 0)
		{
			pb(a, b);
			size--;
		}
		else if (position <= size / 2)
			ra(a);
		else
			rra(a);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}

void	sort_type(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && (*a)->index > (*a)->next->index)
		sa(a);
	else if (size == 3)
	{
		if ((*a)->index < (*a)->next->index
			&& (*a)->next->index < (*a)->next->next->index)
			return ;
		sort_3(a);
	}
	else if (size > 3)
		sort_5(a, b, size);
}
