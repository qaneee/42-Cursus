#include "push_swap.h"

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

static void	append_node(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*temp;

	new = new_node(value);
	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

static int	has_duplicates_stack(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*cmp;

	cur = stack;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (cur->value == cmp->value)
				return (1);
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

static int	process_arg(char *arg, t_stack **stack)
{
	char	**split;
	int		j;
	int		temp;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!ft_atoi(split[j], &temp))
		{
			free_split(split, j);
			return (0);
		}
		append_node(stack, temp);
		j++;
	}
	free_split(split, j - 1);
	return (1);
}

int	validate_args(int argc, char **argv, t_stack **stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || !*argv[i] || !process_arg(argv[i], stack))
			return (free_stack(stack), 0);
		i++;
	}
	if (has_duplicates_stack(*stack))
		return (free_stack(stack), 0);
	return (1);
}
