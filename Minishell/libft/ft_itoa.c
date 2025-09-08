/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:08 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/03 12:05:48 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
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

char	*ft_itoa(int n)
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
