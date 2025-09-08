/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:48:22 by ipogodae          #+#    #+#             */
/*   Updated: 2025/09/03 12:06:40 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigquit_child(int signum)
{
	char	*error_code;

	error_code = ft_itoa(signum);
	write(2, "Quit: ", ft_strlen("Quit: "));
	write(2, error_code, ft_strlen(error_code));
	write(1, "\n", 1);
	g_signal_status = 131;
	free(error_code);
}

void	sigint_child(int signum)
{
	g_signal_status = 128 + signum;
	write(1, "\n", 1);
}

static void	sigint_basic(int signum)
{
	g_signal_status = 128 + signum;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	shell_signals(void)
{
	signal(SIGINT, sigint_basic);
	signal(SIGQUIT, SIG_IGN);
}
