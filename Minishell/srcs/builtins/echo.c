/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:22:05 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/28 12:17:25 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_echo(char **args, int flag_newline, int i)
{
	while (args[i])
	{
		write(STDOUT_FILENO, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (flag_newline)
		write(STDOUT_FILENO, "\n", 1);
}

int	handle_echo(t_command *cmd, char **args, t_env *env)
{
	int	i;
	int	j;
	int	flag_newline;

	i = 1;
	flag_newline = 1;
	(void)cmd;
	(void)env;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break ;
		flag_newline = 0;
		i++;
	}
	if (!args[i] && flag_newline)
		write(STDOUT_FILENO, "\n", 1);
	else if (args[i])
		print_echo(args, flag_newline, i);
	g_signal_status = 0;
	return (0);
}
