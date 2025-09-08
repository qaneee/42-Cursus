/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:58:58 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 19:57:06 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prepare_exit(char **argv, t_env *env, int status)
{
	free_arr(argv);
	clean_env(&env);
	rl_clear_history();
	exit(status);
}

static int	argc_more_than_two(void)
{
	g_signal_status = 1;
	ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
	return (1);
}

static void	print_numeric_error(char **argv)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(argv[1], STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
}

int	handle_exit(t_command *cmd, char **argv, t_env *env)
{
	int	argc;
	int	status;
	int	error;

	(void)cmd;
	argc = 0;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	while (argv[argc])
		argc++;
	if (argc == 1)
		prepare_exit(argv, env, g_signal_status);
	if (argc == 2 && ft_strcmp(argv[1], "--") == 0)
		prepare_exit(argv, env, g_signal_status);
	ft_atoll_strict(argv[1], &status, &error);
	if (error)
	{
		print_numeric_error(argv);
		prepare_exit(argv, env, 2);
	}
	if (argc > 2)
		return (argc_more_than_two());
	prepare_exit(argv, env, status % 256);
	return (0);
}
