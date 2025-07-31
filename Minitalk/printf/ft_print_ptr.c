/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:47:06 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/09 15:48:42 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "0x0", 3));
	len = write(1, "0x", 2);
	len += ft_print_hexlower(ptr);
	return (len);
}
