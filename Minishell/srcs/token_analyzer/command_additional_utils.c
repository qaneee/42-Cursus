/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_additional_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:05:52 by ipogodae          #+#    #+#             */
/*   Updated: 2025/09/03 11:30:41 by ipogodae         ###   ########.fr       */
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
	if (!c->command_path && !c->in_file && !c->out_file && !c->heredoc)
		return (FALSE);
	return (TRUE);
}
