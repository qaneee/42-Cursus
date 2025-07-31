/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexlower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:06:10 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/09 16:08:41 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexlower(unsigned long long n)
{
	char	*hex_lowercase;
	int		new_num[20];
	int		i;
	int		len;

	hex_lowercase = "0123456789abcdef";
	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		new_num[i] = n % 16;
		n /= 16;
		i++;
	}
	len = i;
	while (i > 0)
	{
		i--;
		write(1, &hex_lowercase[new_num[i]], 1);
	}
	return (len);
}
