#include "push_swap.h"

void	free_stack(t_stack **lst)
{
	while (lst && *lst)
		pop_front(lst);
	*lst = NULL;
}

char	**free_split(char **split, int i)
{
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
