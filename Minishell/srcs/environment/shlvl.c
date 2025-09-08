/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:10:36 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/21 13:32:54 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_shlvl(char	*curr_shlvl, int *lvl)
{
	if (!curr_shlvl || !*curr_shlvl || !ft_isdigit(*curr_shlvl))
		*lvl = INIT_SHLVL;
	else
	{
		*lvl = ft_atoi(curr_shlvl) + 1;
		if (*lvl < 0)
			*lvl = 0;
		else if (*lvl > MAX_SHLVL)
		{
			ft_putstr_fd("minishell: warning: SHLVL too high\n", 2);
			*lvl = INIT_SHLVL;
		}
	}
}

void	shlvl_settings(t_env **env)
{
	char	*curr_shlvl;
	char	*new_shlvl;
	int		lvl;

	if (!env || !*env)
		return ;
	curr_shlvl = get_env(*env, "SHLVL");
	process_shlvl(curr_shlvl, &lvl);
	new_shlvl = ft_itoa(lvl);
	if (!new_shlvl)
		return ;
	set_env(env, "SHLVL", new_shlvl);
	free(new_shlvl);
	if (curr_shlvl)
		free(curr_shlvl);
}
