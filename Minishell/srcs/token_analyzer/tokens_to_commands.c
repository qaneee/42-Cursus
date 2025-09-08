/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:03:57 by ipogodae          #+#    #+#             */
/*   Updated: 2025/09/06 20:02:03 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_binary(char *path_or_name, char **result_path, t_env *env)
{
	int			error_code;
	struct stat	st;

	if (ft_strchr(path_or_name, '/'))
	{
		error_code = stat(path_or_name, &st);
		if (error_code)
			return (
				placeholder(path_or_name, "No such file or directory", 127)
			);
		if (S_ISDIR(st.st_mode))
			return (placeholder(path_or_name, "Is a directory", 126));
		if (access(path_or_name, X_OK))
			return (placeholder(path_or_name, "Permission denied", 126));
		return (update_string_field(result_path, path_or_name));
	}
	else
	{
		return (find_binary_in_path(path_or_name, result_path, env));
	}
}

static int	process_arg(
	t_token_vector *t,
	t_command *c,
	size_t *i,
	t_env *env
)
{
	int	error_code;

	if (c->arguments.size == 0)
	{
		if (identify_command(c, t->data[*i].value))
			update_string_field(&c->command_path,
				t->data[*i].value);
		else
		{
			error_code = find_binary(
					t->data[*i].value, &(c->command_path), env);
			if (error_code)
				return (error_code);
		}
	}
	if (push_back_token(
			&(c->arguments),
			t->data[*i].type,
			t->data[*i].value)
	)
	{
		return (1);
	}
	*i += 1;
	return (0);
}

int	consume_token(
	t_token_vector *t,
	t_command *c,
	size_t *i,
	t_env *env
)
{
	if (t->data[*i].type == TOKEN_ARG
		&&ft_strlen(t->data[*i].value) == 0 && c->arguments.size == 0)
		*i += 1;
	else if (t->data[*i].type == TOKEN_ARG)
		return (process_arg(t, c, i, env));
	else if (t->data[*i].type == TOKEN_REDIR_IN)
		return (process_in(&(c->in_file), "No filename after <", t, i));
	else if (t->data[*i].type == TOKEN_REDIR_OUT)
		return (process_out(&(c->out_file), "No filename after >", t, i));
	else if (t->data[*i].type == TOKEN_REDIR_APPEND_OUT)
	{
		c->is_out_append = TRUE;
		return (process_append(&(c->out_file), "No filename after >>", t, i));
	}
	else if (t->data[*i].type == TOKEN_REDIR_ERR)
		return (process_out(&(c->err_file), "No filename after 2>", t, i));
	else if (t->data[*i].type == TOKEN_REDIR_APPEND_ERR)
	{
		c->is_err_append = TRUE;
		return (process_append(&(c->err_file), "No filename after 2>>", t, i));
	}
	else if (t->data[*i].type == TOKEN_HEREDOC)
		return (process_heredoc(&(c->heredoc), "No heredoc after <<", t, i));
	return (0);
}
