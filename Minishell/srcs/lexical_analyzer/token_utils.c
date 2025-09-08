/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:02:51 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/18 16:49:03 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_token(t_token *t)
{
	t->type = TOKEN_UNKNOWN;
	t->value = 0;
}

void	clear_token(t_token *t)
{
	if (t->value)
	{
		free(t->value);
	}
	init_token(t);
}

void	assign_token(t_token *t, char *line)
{
	t->value = line;
	t->type = TOKEN_ARG;
}

void	print_token(t_token *t)
{
	if (t->type == TOKEN_ARG)
		printf("%s", t->value);
	if (t->type == TOKEN_PIPE)
		printf("|");
	if (t->type == TOKEN_REDIR_IN)
		printf("<");
	if (t->type == TOKEN_REDIR_OUT)
		printf(">");
	if (t->type == TOKEN_REDIR_APPEND_OUT)
		printf(">>");
	if (t->type == TOKEN_REDIR_ERR)
		printf("2>");
	if (t->type == TOKEN_REDIR_APPEND_ERR)
		printf("2>>");
	if (t->type == TOKEN_HEREDOC)
		printf("<<");
	if (t->type == TOKEN_UNKNOWN)
		printf("[???]");
}

size_t	get_token_length(t_token_type type)
{
	if (type == TOKEN_UNKNOWN)
		return (0);
	if (type == TOKEN_PIPE)
		return (1);
	if (type == TOKEN_REDIR_IN)
		return (1);
	if (type == TOKEN_REDIR_OUT)
		return (1);
	if (type == TOKEN_REDIR_APPEND_OUT)
		return (2);
	if (type == TOKEN_REDIR_ERR)
		return (2);
	if (type == TOKEN_REDIR_APPEND_ERR)
		return (3);
	if (type == TOKEN_HEREDOC)
		return (2);
	return (0);
}
