/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:13:43 by ipogodae          #+#    #+#             */
/*   Updated: 2025/09/03 11:22:47 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "structs.h"

int		parse_line(char *line, t_token_vector *v, t_env *env);

int		parse_tokens(
			t_token_vector *tokens,
			t_command_vector *commands,
			t_env *env);

int		process_in(
			char **field,
			char *error_msg,
			t_token_vector *tokens,
			size_t *i);
int		process_out(
			char **field,
			char *error_msg,
			t_token_vector *tokens,
			size_t *i);
int		process_append(
			char **field,
			char *error_msg,
			t_token_vector *tokens,
			size_t *i);
int		process_heredoc(
			char **field,
			char *error_msg,
			t_token_vector *tokens,
			size_t *i);

int		consume_token(
			t_token_vector *t,
			t_command *c,
			size_t *i,
			t_env *env);

int		execute_commands(t_command_vector *commands, t_env **env);

#endif
