#include "libft.h"

static void	skip_spaces(const char **str)
{
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
}

static int	set_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi(const char *str, int *out)
{
	long	num;
	int		sign;

	if (!str || !*str)
		return (0);
	skip_spaces(&str);
	sign = set_sign(&str);
	if (!ft_isdigit(*str))
		return (0);
	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > (long)INT_MAX + 1))
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	*out = (int)(num * sign);
	return (1);
}