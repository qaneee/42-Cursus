/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:45:16 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/28 12:25:12 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_pipes(t_command_vector *commands)
{
	size_t	i;
	int		pipefd[2];

	i = 0;
	while (i + 1 < commands->size)
	{
		if (pipe(pipefd) == -1)
		{
			return (1);
		}
		commands->data[i + 1].read_pipe = pipefd[0];
		commands->data[i].write_pipe = pipefd[1];
		if (commands->data[i + 1].is_dummy)
			close(commands->data[i + 1].read_pipe);
		if (commands->data[i].is_dummy)
			close(commands->data[i].write_pipe);
		++i;
	}
	return (0);
}

static void	consume_heredoc(t_command *current_command)
{
	char		*line;

	current_command->heredoc_content = malloc(1);
	current_command->heredoc_content[0] = 0;
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			break ;
		if (ft_strncmp(line, current_command->heredoc, ft_strlen(line)) == 0)
			break ;
		if (current_command->heredoc_content[0])
			update_string_field(
				&(current_command->heredoc_content),
				ft_strjoin(current_command->heredoc_content, "\n")
				);
		update_string_field(
			&(current_command->heredoc_content),
			ft_strjoin(current_command->heredoc_content, line)
			);
	}
}

static int	start_commands(t_command_vector *commands, t_env **env)
{
	size_t	i;

	i = 0;
	while (i < commands->size)
	{
		if (commands->data[i].heredoc)
		{
			consume_heredoc(&(commands->data[i]));
			if (!write_content_in_tmp(&(commands->data[i])))
				return (1);
		}
		if (!commands->data[i].is_dummy)
			execute_one_command(&(commands->data[i]), env, commands);
		if (commands->data[i].heredoc)
			unlink(TMP_FILE);
		++i;
	}
	return (0);
}

int	wait_for_one_command(t_command_vector *commands, size_t i, int status)
{
	if ((!commands->data[i].is_command_builtin
			|| commands->size != 1) && !commands->data[i].is_dummy)
	{
		if (waitpid(commands->data[i].child_process_pid, &status, 0) == -1)
		{
			g_signal_status = 1;
			return (g_signal_status);
		}
	}
	else
		status = g_signal_status;
	if (i + 1 == commands->size)
	{
		if (!commands->data[i].is_command_builtin)
		{
			process_status(status);
		}
		else
			g_signal_status = status;
	}
	return (0);
}

int	execute_commands(t_command_vector *commands, t_env **env)
{
	size_t	i;
	int		error_code;
	int		status;

	status = 0;
	create_pipes(commands);
	if (start_commands(commands, env))
		return (1);
	i = 0;
	while (i < commands->size)
	{
		error_code = wait_for_one_command(commands, i, status);
		if (error_code)
			return (error_code);
		++i;
	}
	return (0);
}
