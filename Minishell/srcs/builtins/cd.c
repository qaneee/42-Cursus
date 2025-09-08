/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:09:28 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 20:03:16 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	change_directory(const char *path, t_env *env)
{
	char	*old_cwd;

	old_cwd = getcwd(NULL, 0);
	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		free(old_cwd);
		return (1);
	}
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd((char *)path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free(old_cwd);
		return (1);
	}
	update_pwd_oldpwd(&env, old_cwd);
	free(old_cwd);
	return (0);
}

static int	cd_no_arguments(t_env *env)
{
	char	*home_dir;
	int		error_code;

	home_dir = get_env(env, "HOME");
	if (!home_dir)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	error_code = change_directory(home_dir, env);
	free(home_dir);
	return (error_code);
}

static int	cd_old_pwd(t_env *env)
{
	char	*old_pwd;
	int		state;

	old_pwd = get_env(env, "OLDPWD");
	if (!old_pwd)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		return (1);
	}
	state = change_directory(old_pwd, env);
	free(old_pwd);
	if (state == 0)
	{
		old_pwd = get_env(env, "PWD");
		ft_putstr_fd(old_pwd, 1);
		ft_putstr_fd("\n", 1);
		free(old_pwd);
	}
	return (state);
}

static int	cd_path(const char *path, t_env *env)
{
	if (!path)
		return (1);
	return (change_directory(path, env));
}

int	handle_cd(t_command *cmd, char **argv, t_env *env)
{
	int	argc;

	(void)cmd;
	argc = 0;
	while (argv[argc])
		argc++;
	if (argc == 1)
		g_signal_status = cd_no_arguments(env);
	else if (argc > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		g_signal_status = 1;
	}
	else if (ft_strncmp(argv[1], "-", 2) == 0)
		g_signal_status = cd_old_pwd(env);
	else
		g_signal_status = cd_path(argv[1], env);
	return (g_signal_status);
}
