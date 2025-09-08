/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_oldpwd_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:20:25 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 19:58:43 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pwd_oldpwd(t_env **env)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		set_env(env, "PWD", cwd);
		free(cwd);
	}
	else
		set_env(env, "PWD", "");
	cwd = get_env(*env, "OLDPWD");
	if (!cwd)
		set_env(env, "OLDPWD", "");
	else
		free(cwd);
}

void	update_pwd_oldpwd(t_env **env, const char *old_path)
{
	char	*cwd;

	if (old_path && *old_path)
		set_env(env, "OLDPWD", (char *)old_path);
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		set_env(env, "PWD", cwd);
		free(cwd);
	}
	else
	{
		ft_putstr_fd("cd: error retrieving current directory:", 2);
		ft_putstr_fd(" getcwd: cannot access parent directories:", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
}
