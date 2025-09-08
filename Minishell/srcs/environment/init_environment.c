/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:45:06 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/21 13:28:02 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_node(const char *key, const char *val)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	if (!new->key)
	{
		free(new);
		return (NULL);
	}
	if (val)
		new->val = ft_strdup(val);
	else
		new->val = ft_strdup("");
	if (!new->val)
	{
		free(new->key);
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	env_add_back(t_env **head, t_env *new)
{
	t_env	*temp;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_env	*norm_sucks(char **envp, t_env *head)
{
	int		i;
	char	*ch;
	char	*key;
	t_env	*new;

	i = 0;
	while (envp && envp[i])
	{
		ch = ft_strchr(envp[i], '=');
		if (ch)
		{
			key = ft_strndup(envp[i], (size_t)(ch - envp[i]));
			new = create_node(key, ch + 1);
			if (!key || !new)
			{
				free(key);
				clean_env(&head);
				return (NULL);
			}
			env_add_back(&head, new);
			free(key);
			i++;
		}
	}
	return (head);
}

t_env	*init_env(char **envp)
{
	t_env	*env;

	env = norm_sucks(envp, NULL);
	if (!env)
		env = create_node("SHLVL", "0");
	shlvl_settings(&env);
	return (env);
}
