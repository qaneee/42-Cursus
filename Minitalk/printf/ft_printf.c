/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:24:56 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/09 15:43:35 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		length += ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_print_num(va_arg(args, int));
	else if (format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		length += ft_print_hexlower(va_arg(args, unsigned int));
	else if (format == 'X')
		length += ft_print_hexupper(va_arg(args, unsigned int));
	else if (format == '%')
		length += ft_print_percent();
	return (length);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			length += ft_format(args, s[i + 1]);
			i++;
		}
		else
		{
			length += ft_print_char(s[i]);
		}
		i++;
	}
	va_end(args);
	return (length);
}
