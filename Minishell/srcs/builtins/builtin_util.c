/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:19:36 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 20:03:12 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_valid(const char *str)
{
	if (!str || !*str || ft_isdigit(*str) || *str == '=')
		return (FALSE);
	while (*str && *str != '=')
	{
		if (*str == '+' && *(str + 1) == '=')
			return (TRUE);
		if (!ft_isalnum(*str) && *str != '_')
			return (FALSE);
		str++;
	}
	if (*str && *str != '=')
		return (FALSE);
	return (TRUE);
}

void	print_export_vars(t_env *env)
{
	while (env)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env->key, STDOUT_FILENO);
		if (env->val)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(env->val, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		env = env->next;
	}
}

void	export_error(char *arg)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	g_signal_status = 1;
}
