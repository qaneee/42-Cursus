#include "push_swap_bonus.h"

static void	exit_error(t_stack **a, t_stack **b)
{
    if (a)
 	   free_stack(a);
    if (b)
 	   free_stack(b);
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit_error(NULL, NULL);
	a = NULL;
	b = NULL;
	if (!validate_args(argc, argv, &a))
		exit_error(&a, &b);
	index_sort(&a);
	read_input(&a, &b);
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
