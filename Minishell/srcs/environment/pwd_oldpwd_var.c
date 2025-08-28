/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_oldpwd_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <arvardan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:20:25 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/21 19:12:48 by arvardan         ###   ########.fr       */
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

	if (old_path)
		set_env(env, "OLDPWD", (char *)old_path);
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		set_env(env, "PWD", cwd);
		free(cwd);
	}
}
