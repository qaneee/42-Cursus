/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:22:58 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/20 17:30:39 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token_type	find_token_type(char *line, size_t *i)
{
	if (line[*i] == '|')
		return (TOKEN_PIPE);
	if (line[*i] == '<')
	{
		if (line[*i + 1] == '<')
			return (TOKEN_HEREDOC);
		else
			return (TOKEN_REDIR_IN);
	}
	if (line[*i] == '>')
	{
		if (line[*i + 1] == '>')
			return (TOKEN_REDIR_APPEND_OUT);
		else
			return (TOKEN_REDIR_OUT);
	}
	if (line[*i] == '2' && line[*i + 1] == '>')
	{
		if (line[*i + 2] == '>')
			return (TOKEN_REDIR_APPEND_ERR);
		else
			return (TOKEN_REDIR_ERR);
	}
	return (TOKEN_UNKNOWN);
}

static t_bool	token_guessed(
	char *line, size_t *i, t_parse_state *state, t_token_type *type)
{
	size_t	token_length;

	token_length = 0;
	if (state->in_double_quotes || state->in_single_quotes)
	{
		return (FALSE);
	}
	*type = find_token_type(line, i);
	token_length = get_token_length(*type);
	*i += token_length;
	return (token_length > 0);
}

static t_bool	belongs_to_token(char *line, t_parse_state *state, size_t i)
{
	if (line[i] == '\"')
	{
		if (!state->in_single_quotes)
		{
			state->in_double_quotes = !state->in_double_quotes;
		}
		return (TRUE);
	}
	if (line[i] == '\'')
	{
		if (!state->in_double_quotes)
		{
			state->in_single_quotes = !state->in_single_quotes;
		}
		return (TRUE);
	}
	if (!is_state_initial(*state))
	{
		return (TRUE);
	}
	return (!ft_strchr(" <>|", line[i]));
}

static char	*compose_token(
	char *line, size_t *i, t_parse_state *state, t_token_vector *v
)
{
	t_token_type	type;
	size_t			left;

	if (token_guessed(line, i, state, &type))
	{
		push_back_token(v, type, 0);
		return (0);
	}
	left = *i;
	while (line[*i] && belongs_to_token(line, state, *i))
		++(*i);
	if (left == *i)
		return (0);
	return (ft_strndup(line + left, *i - left));
}

int	parse_line(char *line, t_token_vector *v, t_env *env)
{
	size_t			i;
	t_parse_state	state;
	char			*buffer;

	init_tokens(v);
	init_parse_state(&state);
	i = 0;
	while (line[i])
	{
		while (line[i] && ft_strchr(" \t", line[i]))
			++i;
		if (!line[i])
			break ;
		buffer = compose_token(line, &i, &state, v);
		if (!buffer)
			continue ;
		buffer = process_raw_token(buffer, env);
		if (push_back_token(v, TOKEN_ARG, buffer))
			return (1);
		free(buffer);
	}
	if (!is_state_initial(state))
		return (print_error("Unclosed quotation mark", 1));
	return (0);
}
