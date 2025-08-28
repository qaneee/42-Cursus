/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <arvardan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:58:58 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/28 13:46:54 by arvardan         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

static t_bool	ft_isnumeric(const char *str)
{
	if (!str || !*str)
		return (FALSE);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static t_bool	check_for_wrong_arg_type(char *arg)
{
	if (!ft_isnumeric(arg))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		return (TRUE);
	}
	return (FALSE);
}

int	handle_exit(t_command *cmd, char **argv, t_env *env)
{
	int	argc;
	int	status;

	argc = 0;
	(void)cmd;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	while (argv[argc])
		argc++;
	if (argc > 2)
	{
		g_signal_status = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	if (argc == 1)
	{
		free_arr(argv);
		clean_env(&env);
		rl_clear_history();
		exit(g_signal_status);
	}
	if (check_for_wrong_arg_type(argv[1]))
	{
		free_arr(argv);
		clean_env(&env);
		rl_clear_history();
		exit(2);
	}
	status = ft_atoi(argv[1]) % 256;
	if (status < 0)
		status += 256;
	free_arr(argv);
	clean_env(&env);
	rl_clear_history();
	exit(status);
}
