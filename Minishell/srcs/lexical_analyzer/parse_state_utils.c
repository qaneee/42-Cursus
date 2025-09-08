/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:17:09 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/12 18:01:02 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_parse_state(t_parse_state *s)
{
	s->in_single_quotes = FALSE;
	s->in_double_quotes = FALSE;
	s->in_curly_braces = FALSE;
}

t_bool	is_state_initial(t_parse_state state)
{
	return (
		!state.in_double_quotes
		&& !state.in_single_quotes
		&& !state.in_curly_braces
	);
}
