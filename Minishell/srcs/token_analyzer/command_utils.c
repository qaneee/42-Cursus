/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:40:12 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/28 12:23:49 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_command_fields(t_command *c)
{
	c->is_command_builtin = FALSE;
	c->command_path = 0;
	c->in_file = 0;
	c->out_file = 0;
	c->err_file = 0;
	c->heredoc = 0;
	c->heredoc_content = 0;
	c->is_err_append = FALSE;
	c->is_out_append = FALSE;
	c->read_pipe = -1;
	c->write_pipe = -1;
	c->child_process_pid = -1;
	c->is_dummy = FALSE;
}

void	init_command(t_command *c)
{
	init_command_fields(c);
	init_tokens(&(c->arguments));
}

int	clear_command(t_command *c)
{
	clear_tokens(&(c->arguments));
	if (c->command_path)
		free(c->command_path);
	if (c->in_file)
		free(c->in_file);
	if (c->out_file)
		free(c->out_file);
	if (c->err_file)
		free(c->err_file);
	if (c->heredoc)
		free(c->heredoc);
	if (c->heredoc_content)
		free(c->heredoc_content);
	init_command_fields(c);
	return (0);
}

void	copy_command(t_command *dst, t_command src)
{
	copy_tokens(&(dst->arguments), src.arguments);
	dst->is_command_builtin = src.is_command_builtin;
	update_string_field(&(dst->command_path), src.command_path);
	update_string_field(&(dst->in_file), src.in_file);
	update_string_field(&(dst->out_file), src.out_file);
	update_string_field(&(dst->err_file), src.err_file);
	update_string_field(&(dst->heredoc), src.heredoc);
	dst->is_err_append = src.is_err_append;
	dst->is_out_append = src.is_out_append;
	dst->read_pipe = src.read_pipe;
	dst->write_pipe = src.write_pipe;
	dst->child_process_pid = src.child_process_pid;
	dst->is_dummy = src.is_dummy;
}
