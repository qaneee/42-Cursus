/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:47:34 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/21 13:36:34 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	env_len(t_env *env)
{
	size_t	len;

	len = 0;
	while (env)
	{
		len++;
		env = env->next;
	}
	return (len);
}

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static size_t	get_text_field_size(t_env *temp)
{
	char	*key;
	char	*val;

	if (temp->key)
		key = temp->key;
	else
		key = "";
	if (temp->val)
		val = temp->val;
	else
		val = "";
	return (ft_strlen(key) + ft_strlen(val) + 2);
}

static char	**env_to_arr_helper(t_env *temp, size_t i, size_t len, char **arr)
{
	size_t	size;

	while (i < len && temp)
	{
		size = get_text_field_size(temp);
		arr[i] = malloc(size);
		if (!arr[i])
		{
			free_arr(arr);
			return (NULL);
		}
		arr[i][0] = '\0';
		ft_strlcpy(arr[i], temp->key, size);
		ft_strlcat(arr[i], "=", size);
		ft_strlcat(arr[i], temp->val, size);
		temp = temp->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**env_to_arr(t_env *env)
{
	size_t	len;
	char	**arr;
	t_env	*temp;

	len = env_len(env);
	temp = env;
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	arr = env_to_arr_helper(temp, 0, len, arr);
	return (arr);
}
