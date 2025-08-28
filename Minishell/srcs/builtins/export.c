/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:30:11 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/21 13:34:17 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_export_vars(t_env *env)
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

static void	handle_key_value(t_env **env, char *arg)
{
	char	*ch;
	char	*key;
	char	*val;

	ch = ft_strchr(arg, '=');
	*ch = '\0';
	key = arg;
	val = ft_strdup(ch + 1);
	if (!val)
	{
		g_signal_status = 1;
		*ch = '=';
		return ;
	}
	set_env(env, key, val);
	free(val);
	*ch = '=';
}

static void	handle_key_only(t_env **env, char *arg)
{
	char	*curr_val;
	char	*new_val;

	curr_val = get_env(*env, arg);
	new_val = ft_strdup(curr_val);
	if (curr_val)
		free(curr_val);
	set_env(env, arg, new_val);
	free(new_val);
}

int	handle_export(t_command *cmd, char **argv, t_env **env)
{
	int		i;
	char	*ch;

	i = 1;
	(void)cmd;
	g_signal_status = 0;
	if (!argv[i])
	{
		print_export_vars(*env);
		return (g_signal_status);
	}
	while (argv[i])
	{
		ch = ft_strchr(argv[i], '=');
		if (!is_valid(argv[i]))
			export_error(argv[i]);
		else if (ch)
			handle_key_value(env, argv[i]);
		else
			handle_key_only(env, argv[i]);
		i++;
	}
	return (g_signal_status);
}
