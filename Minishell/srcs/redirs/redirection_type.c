/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:31:19 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 19:58:02 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	redir_in(t_command *cmd)
{
	int	fd;
	int	error_code;

	if (cmd->in_file)
	{
		fd = open(cmd->in_file, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(cmd->in_file, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			return (FALSE);
		}
	}
	else if (cmd->read_pipe != -1)
		fd = cmd->read_pipe;
	else
		return (TRUE);
	error_code = dup2(fd, STDIN_FILENO);
	close(fd);
	return (error_code != -1);
}

static t_bool	redir_out(t_command *cmd)
{
	int	fd;
	int	error_code;

	if (cmd->out_file)
	{
		if (cmd->is_out_append)
			fd = open(cmd->out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(cmd->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(cmd->out_file, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			return (FALSE);
		}
	}
	else if (cmd->write_pipe != -1)
		fd = cmd->write_pipe;
	else
		return (TRUE);
	error_code = dup2(fd, STDOUT_FILENO);
	close(fd);
	return (error_code != -1);
}

static t_bool	redir_error_mgt(t_command *cmd)
{
	int	fd;

	if (cmd->err_file)
	{
		if (cmd->is_err_append)
			fd = open(cmd->err_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(cmd->err_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (FALSE);
		dup2(fd, STDERR_FILENO);
		close(fd);
	}
	return (TRUE);
}

static t_bool	redir_heredoc(t_command *cmd)
{
	int	fd;

	if (cmd->heredoc)
	{
		if (!write_content_in_tmp(cmd))
			return (FALSE);
		fd = open(TMP_FILE, O_RDONLY);
		if (fd == -1)
		{
			perror("minishell");
			return (FALSE);
		}
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			perror("minishell");
			close(fd);
			return (FALSE);
		}
		close(fd);
		unlink(TMP_FILE);
	}
	return (TRUE);
}

t_bool	apply_redirection(t_command *cmd)
{
	if (!redir_in(cmd))
		return (FALSE);
	if (!redir_out(cmd))
		return (FALSE);
	if (!redir_error_mgt(cmd))
		return (FALSE);
	if (!redir_heredoc(cmd))
		return (FALSE);
	return (TRUE);
}
