/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:13:40 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/06 19:58:16 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(t_env *env, const char *key)
{
	if (!key || !env)
		return (NULL);
	if (ft_strcmp(key, "?\0") == 0)
	{
		return (ft_itoa(g_signal_status));
	}
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (ft_strdup(env->val));
		env = env->next;
	}
	return (NULL);
}

void	set_env(t_env **env, const char *key, char *val)
{
	t_env	*temp;
	t_env	*new_node;

	if (!env || !key)
		return ;
	temp = *env;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
		{
			free(temp->val);
			temp->val = ft_strdup(val);
			return ;
		}
		temp = temp->next;
	}
	new_node = create_node(key, val);
	env_add_back(env, new_node);
}

void	unset_env(t_env **env, const char *key)
{
	t_env	*temp;
	t_env	*prev;

	if (!env || !*env || !key)
		return ;
	temp = *env;
	prev = NULL;
	while (temp)
	{
		if (temp->key && ft_strcmp(temp->key, key) == 0)
		{
			if (prev == NULL)
				*env = temp->next;
			else
				prev->next = temp->next;
			free(temp->key);
			free(temp->val);
			free(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

void	print_env(t_env *env)
{
	if (!env)
		return ;
	while (env)
	{
		if (env->key && env->val)
			printf("%s=%s\n", env->key, env->val);
		env = env->next;
	}
}

void	clean_env(t_env **env)
{
	t_env	*temp;

	if (!env)
		return ;
	while (*env)
	{
		temp = (*env)->next;
		free((*env)->key);
		free((*env)->val);
		free(*env);
		*env = temp;
	}
	*env = NULL;
}
