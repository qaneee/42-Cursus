#include "push_swap.h"

static t_stack	*copy_stack(t_stack **a)
{
	t_stack	*res;
	t_stack	*head;

	head = *a;
	res = NULL;
	while (head)
	{
		push_back(&res, head->value, head->index);
		head = head->next;
	}
	return (res);
}

static void	sort_stack(t_stack **a)
{
	t_stack		*temp;
	int			sorted;

	if (!a || !*a || !(*a)->next)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		temp = *a;
		while (temp->next)
		{
			if (temp->value > temp->next->value)
			{
				ft_swap(&(temp->value), &(temp->next->value));
				sorted = 0;
			}
			temp = temp->next;
		}
	}
}

static void	assign_indices(t_stack *copy)
{
	int			idx;
	t_stack		*temp;

	idx = 0;
	temp = copy;
	while (temp)
	{
		temp->index = idx++;
		temp = temp->next;
	}
}

void	index_sort(t_stack **a)
{
	t_stack	*head;
	t_stack	*copy;
	t_stack	*temp;

	if (!a || !*a)
		return ;
	copy = copy_stack(a);
	sort_stack(&copy);
	assign_indices(copy);
	head = *a;
	while (head)
	{
		temp = copy;
		while (temp)
		{
			if (head->value == temp->value)
			{
				head->index = temp->index;
				break ;
			}
			temp = temp->next;
		}
		head = head->next;
	}
	free_stack(&copy);
}
