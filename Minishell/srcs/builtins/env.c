/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <arvardan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:43:48 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/19 20:08:23 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_env(t_command *cmd, char **argv, t_env **env)
{
	(void)cmd;
	(void)argv;
	if (env && *env)
		print_env(*env);
	g_signal_status = 0;
	return (g_signal_status);
}
