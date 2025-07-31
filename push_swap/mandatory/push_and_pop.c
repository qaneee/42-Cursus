#include "push_swap.h"

void	push_front(t_stack **lst, int val, int ind)
{
	t_stack	*new_node;

	if (!lst)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new_node->value = val;
	new_node->index = ind;
	new_node->next = NULL;
	if (*lst)
	{
		new_node->next = *lst;
		*lst = new_node;
	}
	else
		*lst = new_node;
}

void	push_back(t_stack **lst, int val, int ind)
{
	t_stack	*new_node;
	t_stack	*head;

	if (!lst)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new_node->value = val;
	new_node->index = ind;
	new_node->next = NULL;
	if (*lst)
	{
		head = *lst;
		while (head->next)
			head = head->next;
		head->next = new_node;
	}
	else
		*lst = new_node;
}

void	pop_front(t_stack **lst)
{
	t_stack	*head;

	if (lst && *lst)
	{
		head = (*lst)->next;
		free(*lst);
		*lst = head;
	}
}

void	pop_back(t_stack **lst)
{
	t_stack	*head;

	if (!lst || !*lst)
		return ;
	head = *lst;
	if (!head->next)
	{
		pop_front(lst);
		return ;
	}
	while (head->next->next)
		head = head->next;
	free(head->next);
	head->next = NULL;
}

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}
