/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_additional_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:05:52 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/18 16:53:50 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_command *c)
{
	printf("Command %s executed\n", c->command_path);
}

t_bool	is_command_complete(t_command *c)
{
	if (!c)
		return (FALSE);
	if (c->is_command_builtin)
		return (c->command_path != NULL);
	return (c->command_path != NULL);
}
