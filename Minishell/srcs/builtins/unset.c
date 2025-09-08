/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:46:17 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 19:57:17 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_unset(t_env **env, char **argv)
{
	int	i;

	i = 1;
	g_signal_status = 0;
	if (!argv[i] || !env || !*env)
		return (g_signal_status);
	while (argv[i])
	{
		unset_env(env, argv[i]);
		i++;
	}
	return (g_signal_status);
}
