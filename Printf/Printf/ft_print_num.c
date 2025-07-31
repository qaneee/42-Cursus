/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:03:19 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/11 13:16:33 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	if (n == -2147483648)
		return (11);
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_digits(char *str, long int num, int len)
{
	while (len > 0)
	{
		str[len - 1] = '0' + (num % 10);
		num /= 10;
		len--;
	}
}

static char	*ft_strdup(const char *s)
{
	int		len;
	char	*result;
	int		i;

	len = 0;
	while (s[len])
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static char	*ft_itoa(long int n)
{
	char		*str;
	int			len;
	long int	num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	if (n < 0)
		num = -n;
	len = ft_num_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		len--;
	}
	ft_fill_digits(str + (n < 0), num, len);
	return (str);
}

int	ft_print_num(int n)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_itoa(n);
	len = ft_print_string(nbr);
	free(nbr);
	return (len);
}
