/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:17:39 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/28 12:25:49 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

typedef struct s_env	t_env;

t_bool	execute_one_command(
			t_command *cmd,
			t_env **env,
			t_command_vector *commands);

int		handle_external_command(
			t_command *cmd,
			char **argv,
			t_env **env,
			t_command_vector *commands);
void	close_pipes(t_command *cmd);

t_bool	identify_command(t_command *cmd, char *cmd_name);
void	check_command(
			t_command *cmd,
			char **argv,
			t_env **env,
			t_command_vector *commands);
void	restore_fds(int stdin_fd, int stdout_fd, int stderr_fd);
t_bool	apply_builtin_redirections(
			t_command *cmd,
			int *saved_stdin,
			int *saved_stdout,
			int *saved_stderr);
t_bool	apply_builtin_redirections_parent(
			t_command *cmd,
			int *saved_stdin,
			int *saved_stdout,
			int *saved_stderr);
void	process_status(int status);

#endif
