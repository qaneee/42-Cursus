/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:04:29 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/09 16:05:28 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexupper(unsigned long long n)
{
	char	*hex_uppercase;
	int		new_num[20];
	int		i;
	int		len;

	hex_uppercase = "0123456789ABCDEF";
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
		write(1, &hex_uppercase[new_num[i]], 1);
	}
	return (len);
}
