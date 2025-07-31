/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:38 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/11 13:38:37 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_print_char(int c);
int	ft_print_percent(void);
int	ft_print_string(char *s);
int	ft_print_num(int n);
int	ft_print_hexlower(unsigned long long n);
int	ft_print_hexupper(unsigned long long n);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_unsigned(unsigned int n);
int	ft_printf(const char *s, ...);
#endif
