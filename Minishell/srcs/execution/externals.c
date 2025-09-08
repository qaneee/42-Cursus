/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:24:48 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/03 11:29:42 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(t_command *cmd)
{
	if (cmd->read_pipe != -1)
		close(cmd->read_pipe);
	if (cmd->write_pipe != -1)
		close(cmd->write_pipe);
}

static void	child_process(
	t_command *cmd, char **argv, char **envp, t_command_vector *commands)
{
	size_t	i;

	if (!apply_redirection(cmd))
		exit (1);
	if (cmd->is_command_builtin)
		exit (0);
	i = 0;
	while (i < commands->size)
	{
		close_pipes(&(commands->data[i++]));
	}
	if (!cmd->command_path)
		exit(0);
	execve(cmd->command_path, argv, envp);
	exit (g_signal_status);
}

int	handle_external_command(
	t_command *cmd, char **argv, t_env **env, t_command_vector *commands)
{
	char	**envp;

	envp = env_to_arr(*env);
	if (!envp)
		return (1);
	child_process(cmd, argv, envp, commands);
	free_arr(envp);
	return (g_signal_status);
}
