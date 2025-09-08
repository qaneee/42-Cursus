/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fields.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:18:33 by ipogodae          #+#    #+#             */
/*   Updated: 2025/09/06 20:02:56 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_in(
	char **field, char *error_msg, t_token_vector *tokens, size_t *i
)
{
	int	fd;

	if (*i + 1 >= tokens->size)
		return (print_error(error_msg, 2));
	if (tokens->data[*i + 1].type != TOKEN_ARG)
		return (print_error(error_msg, 2));
	if (update_string_field(field, tokens->data[*i + 1].value))
	{
		*i += 2;
		return (1);
	}
	fd = open(tokens->data[*i + 1].value, O_RDONLY);
	*i += 2;
	if (fd == -1 && errno == EACCES)
		return (
			placeholder(tokens->data[*i - 1].value, "Permission denied", 1));
	if (fd == -1 && errno == ENOENT)
		return (
			placeholder(
				tokens->data[*i - 1].value, "No such file or directory", 1));
	close(fd);
	return (fd == -1);
}

int	process_out(
	char **field, char *error_msg, t_token_vector *tokens, size_t *i
)
{
	int	fd;

	if (*i + 1 >= tokens->size)
		return (print_error(error_msg, 2));
	if (tokens->data[*i + 1].type != TOKEN_ARG)
		return (print_error(error_msg, 2));
	if (update_string_field(field, tokens->data[*i + 1].value))
	{
		*i += 2;
		return (1);
	}
	fd = open(
			tokens->data[*i + 1].value,
			O_WRONLY | O_CREAT | O_TRUNC,
			0777);
	*i += 2;
	if (fd == -1 && errno == EACCES)
		return (
			placeholder(tokens->data[*i - 1].value, "Permission denied", 1));
	if (fd == -1 && errno == ENOENT)
		return (
			placeholder(tokens->data[*i - 1].value,
				"No such file or directory", 1));
	close(fd);
	return (fd == -1);
}

int	process_append(
	char **field, char *error_msg, t_token_vector *tokens, size_t *i
)
{
	int	fd;

	if (*i + 1 >= tokens->size)
		return (print_error(error_msg, 2));
	if (tokens->data[*i + 1].type != TOKEN_ARG)
		return (print_error(error_msg, 2));
	if (update_string_field(field, tokens->data[*i + 1].value))
	{
		*i += 2;
		return (1);
	}
	fd = open(
			tokens->data[*i + 1].value,
			O_WRONLY | O_CREAT | O_APPEND,
			0777);
	*i += 2;
	if (fd == -1 && errno == EACCES)
		return (
			placeholder(tokens->data[*i - 1].value, "Permission denied", 1));
	if (fd == -1 && errno == ENOENT)
		return (
			placeholder(
				tokens->data[*i - 1].value, "No such file or directory", 1));
	close(fd);
	return (fd == -1);
}

int	process_heredoc(
	char **field, char *error_msg, t_token_vector *tokens, size_t *i
)
{
	if (*i + 1 >= tokens->size)
		return (print_error(error_msg, 2));
	if (tokens->data[*i + 1].type != TOKEN_ARG)
		return (print_error(error_msg, 2));
	if (update_string_field(field, tokens->data[*i + 1].value))
	{
		*i += 2;
		return (1);
	}
	*i += 2;
	return (0);
}
