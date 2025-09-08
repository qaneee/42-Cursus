/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:15:25 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 20:06:15 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}

static const char	*is_whitespace_sign(const char *str, int *sign)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static int	is_overflow(unsigned long long num, int digit, int sign)
{
	unsigned long long	lim;

	if (sign == 1)
		lim = LLONG_MAX;
	else
		lim = (unsigned long long)LLONG_MAX + 1ULL;
	if (num > lim / 10)
		return (1);
	if (num == lim / 10 && (unsigned long long)digit > lim % 10)
		return (1);
	return (0);
}

static int	get_number(const char *str, int *sign, unsigned long long *num)
{
	int	digit;

	*num = 0;
	str = is_whitespace_sign(str, sign);
	if (!*str)
		return (1);
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (1);
		digit = *str - '0';
		if (is_overflow(*num, digit, *sign))
			return (1);
		*num = *num * 10 + digit;
		str++;
	}
	return (0);
}

long long	ft_atoll_strict(const char *str, int *code_to_exit, int *error)
{
	unsigned long long	num;
	int					sign;
	long long			val;

	sign = 1;
	if (!str || get_number(str, &sign, &num))
	{
		*error = 1;
		return (0);
	}
	if (sign == 1)
		val = (long long)num;
	else
		val = -(long long)num;
	*code_to_exit = (val % 256 + 256) % 256;
	*error = 0;
	return (val);
}
