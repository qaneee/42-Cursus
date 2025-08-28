/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 00:42:39 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/20 17:36:21 by ipogodae         ###   ########.fr       */
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
void	unset_error(char *arg);
t_bool	is_valid_unset(const char *str);

#endif
