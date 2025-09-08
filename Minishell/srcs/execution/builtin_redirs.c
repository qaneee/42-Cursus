/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:19:58 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 20:26:59 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	restore_fds(int stdin_fd, int stdout_fd, int stderr_fd)
{
	if (stdin_fd != -1)
	{
		dup2(stdin_fd, STDIN_FILENO);
		close(stdin_fd);
	}
	if (stdout_fd != -1)
	{
		dup2(stdout_fd, STDOUT_FILENO);
		close(stdout_fd);
	}
	if (stderr_fd != -1)
	{
		dup2(stderr_fd, STDERR_FILENO);
		close(stderr_fd);
	}
}

t_bool	apply_builtin_redirections(
	t_command *cmd,
	int *saved_stdin,
	int *saved_stdout,
	int *saved_stderr)
{
	*saved_stdin = dup(STDIN_FILENO);
	*saved_stdout = dup(STDOUT_FILENO);
	*saved_stderr = dup(STDERR_FILENO);
	if (*saved_stdin == -1 || *saved_stdout == -1 || *saved_stderr == -1)
	{
		if (*saved_stdin != -1)
			close(*saved_stdin);
		if (*saved_stdout != -1)
			close(*saved_stdout);
		if (*saved_stderr != -1)
			close(*saved_stderr);
		return (FALSE);
	}
	if (!apply_redirection(cmd))
	{
		restore_fds(*saved_stdin, *saved_stdout, *saved_stderr);
		return (FALSE);
	}
	close(*saved_stdin);
	close(*saved_stdout);
	close(*saved_stderr);
	return (TRUE);
}

t_bool	apply_builtin_redirections_parent(
	t_command *cmd,
	int *saved_stdin,
	int *saved_stdout,
	int *saved_stderr)
{
	*saved_stdin = dup(STDIN_FILENO);
	*saved_stdout = dup(STDOUT_FILENO);
	*saved_stderr = dup(STDERR_FILENO);
	if (*saved_stdin == -1 || *saved_stdout == -1 || *saved_stderr == -1)
	{
		if (*saved_stdin != -1)
			close(*saved_stdin);
		if (*saved_stdout != -1)
			close(*saved_stdout);
		if (*saved_stderr != -1)
			close(*saved_stderr);
		return (FALSE);
	}
	if (!apply_redirection(cmd))
	{
		restore_fds(*saved_stdin, *saved_stdout, *saved_stderr);
		return (FALSE);
	}
	return (TRUE);
}

void	process_status(int status)
{
	if (WIFEXITED(status))
		g_signal_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (status >= 256)
		{
			status /= 256;
			g_signal_status = WTERMSIG(status);
		}
		else
			g_signal_status = 128 + WTERMSIG(status);
	}
	else
		g_signal_status = 1;
}
