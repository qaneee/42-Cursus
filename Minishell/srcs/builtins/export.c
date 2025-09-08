/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:30:11 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 19:57:44 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	curr_val = get_env(*env, arg);
	if (!curr_val)
		return ;
	set_env(env, arg, curr_val);
	free(curr_val);
}

static void	concat_helper(t_env **env, char *key, char *val)
{
	char	*old_val;
	char	*new_val;

	old_val = get_env(*env, key);
	if (old_val)
	{
		new_val = ft_strjoin(old_val, val);
		set_env(env, key, new_val);
		free(old_val);
		free(new_val);
	}
	else
		set_env(env, key, val);
}

static void	export_concat(t_env **env, char *arg)
{
	char	*c;
	char	*key;
	char	*val;

	c = ft_strnstr(arg, "+=", ft_strlen(arg));
	if (!c)
		return ;
	*c = '\0';
	key = arg;
	val = ft_strdup(c + 2);
	if (!val)
	{
		g_signal_status = 1;
		*c = '+';
		return ;
	}
	concat_helper(env, key, val);
	free (val);
	*c = '+';
}

int	handle_export(t_command *cmd, char **argv, t_env **env)
{
	int		i;

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
		if (!is_valid(argv[i]))
			export_error(argv[i]);
		else if (ft_strnstr(argv[i], "+=", ft_strlen(argv[i])))
			export_concat(env, argv[i]);
		else if (ft_strchr(argv[i], '='))
			handle_key_value(env, argv[i]);
		else
			handle_key_only(env, argv[i]);
		i++;
	}
	return (g_signal_status);
}
