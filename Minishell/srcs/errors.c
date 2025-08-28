/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:47:14 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/21 13:40:37 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int	print_error(char *msg, int exit_code)
{
	g_signal_status = exit_code;
	write(2, "Error: ", ft_strlen("Error: "));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", ft_strlen("\n"));
	return (exit_code);
}
