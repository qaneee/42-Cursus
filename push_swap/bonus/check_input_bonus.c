#include "push_swap_bonus.h"

static void	invalid_input(char *s, t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	free(s);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	check_type(char *str, t_stack **a, t_stack **b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa_check(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb_check(b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss_check(a, b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa_check(a, b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb_check(a, b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra_check(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb_check(b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr_check(a, b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra_check(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb_check(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr_check(a, b);
	else
		invalid_input(str, a, b);
}

void	read_input(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str)
		{
			if (str[0] == '\n')
			    get_next_line(-1);
			check_type(str, a, b);
		}
		else
			break ;
		free(str);
	}
}
