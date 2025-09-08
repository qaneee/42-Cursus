/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:45:58 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 20:03:21 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_pwd(t_command *cmd, char **argv, t_env *env)
{
	char	*cwd;
	char	*pwd;

	(void)cmd;
	(void)argv;
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		printf("%s\n", cwd);
		free(cwd);
		return (0);
	}
	pwd = get_env(env, "PWD");
	if (pwd)
	{
		printf("%s\n", pwd);
		free(pwd);
	}
	return (0);
}
