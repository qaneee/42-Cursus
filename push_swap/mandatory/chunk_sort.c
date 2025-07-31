#include "push_swap.h"

static int	max_index_position(t_stack **b)
{
	int			max;
	int			position;
	int			i;
	t_stack		*temp;

	max = (*b)->index;
	position = 0;
	i = 0;
	temp = *b;
	if (!temp)
		return (-1);
	while (temp)
	{
		if (temp->index > max)
		{
			max = temp->index;
			position = i;
		}
		temp = temp->next;
		i++;
	}
	return (position);
}

static void	pa_back(t_stack **a, t_stack **b)
{
	int	size;
	int	position;

	while (*b)
	{
		if (!*b)
			break ;
		size = stack_size(*b);
		position = max_index_position(b);
		if (position <= size / 2)
		{
			while (position-- > 0)
				rb(b);
		}
		else
		{
			position = size - position;
			while (position-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

static void	push_chunks(t_stack **a, t_stack **b, int chunk_size)
{
	int	i;
	int	pushed;
	int	size;

	i = 0;
	pushed = 0;
	size = stack_size(*a);
	while (pushed < size)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
			pushed++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
			pushed++;
		}
		else
			ra(a);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	if (size == 2 || size == 3 || size == 4 || size == 5)
	{
		sort_type(a, b, size);
		return ;
	}
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks(a, b, chunk_size);
	pa_back(a, b);
}
