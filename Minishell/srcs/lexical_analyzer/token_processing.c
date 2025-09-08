/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:52:51 by ipogodae          #+#    #+#             */
/*   Updated: 2025/09/06 19:17:11 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	compose_string(
	char *raw_token,
	size_t *i,
	t_char_vector *expansion,
	t_parse_state *state
)
{
	++*i;
	if (raw_token[*i] == '{')
	{
		state->in_curly_braces = TRUE;
		++*i;
	}
	if (raw_token[*i] == '?')
	{
		push_back_char(expansion, raw_token[(*i)++]);
	}
	else
	{
		while (ft_isalnum(raw_token[*i])
			|| raw_token[*i] == '?' || raw_token[*i] == '_')
			push_back_char(expansion, raw_token[(*i)++]);
	}
	if (raw_token[*i] == '}')
	{
		state->in_curly_braces = FALSE;
		++*i;
	}
	--*i;
}

static int	process_expansion(
	char *raw_token, size_t *i, t_char_vector *token, t_env *env
)
{
	t_char_vector	expansion;
	t_parse_state	state;
	char			*value;
	size_t			j;

	init_string(&expansion);
	init_parse_state(&state);
	compose_string(raw_token, i, &expansion, &state);
	if (expansion.size == 0)
		push_back_char(token, '$');
	value = get_env(env, expansion.data);
	clear_string(&expansion);
	if (!value)
		return (0);
	if (!is_state_initial(state))
	{
		free(value);
		return (1);
	}
	j = 0;
	while (value[j])
		push_back_char(token, value[j++]);
	free(value);
	return (0);
}

static void	process_characters(
	char *raw_token, size_t *i, t_char_vector *v, t_parse_state *state
)
{
	if (raw_token[*i] == '"')
	{
		if (state->in_single_quotes)
			push_back_char(v, raw_token[*i]);
		else
			state->in_double_quotes = !state->in_double_quotes;
	}
	if (raw_token[*i] == '\'')
	{
		if (state->in_double_quotes)
			push_back_char(v, raw_token[*i]);
		else
			state->in_single_quotes = !state->in_single_quotes;
	}
}

char	*process_raw_token(char *raw_token, t_env *env)
{
	t_char_vector	v;
	t_parse_state	state;
	size_t			i;

	init_string(&v);
	init_parse_state(&state);
	i = 0;
	while (raw_token[i])
	{
		process_characters(raw_token, &i, &v, &state);
		if (raw_token[i] == '$' && !state.in_single_quotes)
			process_expansion(raw_token, &i, &v, env);
		else if (!ft_strchr("'\"", raw_token[i]))
			push_back_char(&v, raw_token[i]);
		++i;
	}
	free(raw_token);
	return (v.data);
}
