/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:24:29 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/03 12:02:51 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	identify_command(t_command *cmd, char *cmd_name)
{
	if (!cmd_name || !cmd)
		return (FALSE);
	if (ft_strncmp(cmd_name, "echo", 5) == 0
		|| ft_strncmp(cmd_name, "pwd", 4) == 0
		|| ft_strncmp(cmd_name, "cd", 3) == 0
		|| ft_strncmp(cmd_name, "export", 7) == 0
		|| ft_strncmp(cmd_name, "unset", 6) == 0
		|| ft_strncmp(cmd_name, "env", 4) == 0
		|| ft_strncmp(cmd_name, "exit", 5) == 0)
	{
		cmd->is_command_builtin = TRUE;
		return (TRUE);
	}
	else
	{
		cmd->is_command_builtin = FALSE;
		return (FALSE);
	}
}

static int	handle_builtin_commands_inner(
	t_command *cmd, char **argv, t_env **env)
{
	if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return (handle_pwd(cmd, argv, *env));
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (handle_echo(cmd, argv, *env));
	else if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (handle_cd(cmd, argv, *env));
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return (handle_export(cmd, argv, env));
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (handle_unset(env, argv));
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		return (handle_env(cmd, argv, env));
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		return (handle_exit(cmd, argv, *env));
	return (-1);
}

static int	handle_builtin_commands(
	t_command *cmd, char **argv, t_env **env, t_bool is_parent)
{
	int	saved_stdin;
	int	saved_stdout;
	int	saved_stderr;
	int	return_code;

	if (is_parent)
		return_code = apply_builtin_redirections_parent(
				cmd, &saved_stdin, &saved_stdout, &saved_stderr);
	else
		return_code = apply_builtin_redirections(
				cmd, &saved_stdin, &saved_stdout, &saved_stderr);
	if (!return_code)
	{
		restore_fds(saved_stdin, saved_stdout, saved_stderr);
		g_signal_status = 1;
		return (g_signal_status);
	}
	return_code = handle_builtin_commands_inner(cmd, argv, env);
	restore_fds(saved_stdin, saved_stdout, saved_stderr);
	return (return_code);
}

static void	handle_command(
	t_command *cmd, char **argv, t_env **env, t_command_vector *commands)
{
	if (cmd->is_command_builtin)
	{
		exit(handle_builtin_commands(cmd, argv, env, FALSE));
	}
	else
	{
		handle_external_command(cmd, argv, env, commands);
	}
}

void	check_command(
	t_command *cmd, char **argv, t_env **env, t_command_vector *commands)
{
	pid_t	pid;

	if (commands->size == 1 && cmd->is_command_builtin)
	{
		g_signal_status = handle_builtin_commands(cmd, argv, env, TRUE);
		return ;
	}
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		signal(SIGQUIT, 0);
		handle_command(cmd, argv, env, commands);
	}
	else
	{
		signal(SIGINT, sigint_child);
		signal(SIGQUIT, sigquit_child);
		cmd->child_process_pid = pid;
		close_pipes(cmd);
	}
}
