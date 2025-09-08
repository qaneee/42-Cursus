/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_commands2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 07:50:23 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/03 11:52:42 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	end_or_pipe_case(
	t_token_vector *tokens,
	t_command_vector *commands,
	t_command *current_command,
	size_t *i
)
{
	if (*i == tokens->size
		&& !is_command_complete(current_command) && !commands->size)
		return (0);
	if (!is_command_complete(current_command))
		return (print_error("Command is not complete", 2));
	push_back_command(commands, *current_command);
	clear_command(current_command);
	init_command(current_command);
	if ((*i)++ == tokens->size)
		return (0);
	return (-1);
}

static int	syntax_error(
	t_token_vector *tokens,
	t_command_vector *commands,
	t_command *current_command,
	size_t *i
)
{
	current_command->is_dummy = TRUE;
	push_back_command(commands, *current_command);
	clear_command(current_command);
	init_command(current_command);
	current_command->is_dummy = TRUE;
	while (*i < tokens->size && tokens->data[*i].type != TOKEN_PIPE)
	{
		++(*i);
	}
	++(*i);
	return (g_signal_status);
}

static void	error_case(
	t_token_vector *tokens,
	t_command_vector *commands,
	t_command *current_command,
	size_t *i
)
{
	current_command->is_dummy = TRUE;
	push_back_command(commands, *current_command);
	clear_command(current_command);
	init_command(current_command);
	while (*i < tokens->size && tokens->data[*i].type != TOKEN_PIPE)
	{
		++(*i);
	}
	++(*i);
}

int	parse_tokens(t_token_vector *tokens, t_command_vector *commands, t_env *env)
{
	t_command	current_command;
	size_t		i;
	int			result;

	init_commands(commands);
	init_command(&current_command);
	i = 0;
	while (i < tokens->size + 1)
	{
		g_signal_status = 0;
		if (i == tokens->size || tokens->data[i].type == TOKEN_PIPE)
		{
			result = end_or_pipe_case(tokens, commands, &current_command, &i);
			if (result >= 0)
				return (ft_min(result, 1));
			continue ;
		}
		g_signal_status = consume_token(tokens, &current_command, &i, env);
		if (g_signal_status == 2)
			return (syntax_error(tokens, commands, &current_command, &i));
		else if (g_signal_status)
			error_case(tokens, commands, &current_command, &i);
	}
	return (g_signal_status);
}
