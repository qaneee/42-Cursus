/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 00:42:39 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 19:56:23 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		handle_pwd(t_command *cmd, char **argv, t_env *env);
int		handle_echo(t_command *cmd, char **argv, t_env *env);
int		handle_cd(t_command *cmd, char **argv, t_env *env);
int		handle_env(t_command *cmd, char **argv, t_env **env);
int		handle_export(t_command *cmd, char **argv, t_env **env);
int		handle_unset(t_env **env, char **argv);
int		handle_exit(t_command *cmd, char **argv, t_env *env);
void	export_error(char *arg);
t_bool	is_valid(const char *str);
void	print_export_vars(t_env *env);

#endif
