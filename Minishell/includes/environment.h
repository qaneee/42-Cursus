/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <arvardan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:20:38 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/19 20:25:19 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}	t_env;

t_env	*create_node(const char *key, const char *val);
t_env	*init_env(char **envp);
char	*get_env(t_env *env, const char *key);
void	set_env(t_env **env, const char *key, char *val);
void	unset_env(t_env **env, const char *key);
void	print_env(t_env *env);
void	clean_env(t_env **env);
char	**env_to_arr(t_env *env);
void	free_arr(char **arr);
void	init_pwd_oldpwd(t_env **env);
void	update_pwd_oldpwd(t_env **env, const char *old_path);
void	shlvl_settings(t_env **env);
void	env_add_back(t_env **head, t_env *new);

#endif
