/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:57:46 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/21 13:50:28 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_strings(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i++]);
	}
	free(strings);
}

t_bool	exists_path(char *path)
{
	struct stat	st;

	return (stat(path, &st) == 0);
}

int	generate_candidate_path(char *path, char *name, char **dst)
{
	char	*buffer;

	buffer = ft_strjoin(path, "/");
	if (!buffer)
	{
		return (print_error("Failed to malloc", 1));
	}
	*dst = ft_strjoin(buffer, name);
	free(buffer);
	if (!*dst)
	{
		return (print_error("Failed to malloc", 1));
	}
	return (0);
}

char	**generate_path_env_paths(t_env *env)
{
	char	**path_env_paths;
	char	*env_path;
	char	*initial_path;

	env_path = get_env(env, "PATH");
	if (!env_path || !*env_path)
		initial_path = ft_strdup(
				"/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	else
		initial_path = ft_strjoin(
				env_path, ":/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	if (env_path)
		free(env_path);
	if (!initial_path)
		return (NULL);
	path_env_paths = ft_split(initial_path, ':');
	free(initial_path);
	return (path_env_paths);
}

int	find_binary_in_path(char *name, char **result_path, t_env *env)
{
	char	**path_env_paths;
	char	*candidate_path;
	size_t	i;

	path_env_paths = generate_path_env_paths(env);
	if (!path_env_paths)
		return (print_error("Failed to split PATH", 1));
	i = 0;
	while (path_env_paths[i])
	{
		if (generate_candidate_path(path_env_paths[i++], name, &candidate_path))
		{
			cleanup_strings(path_env_paths);
			return (1);
		}
		if (exists_path(candidate_path))
		{
			*result_path = candidate_path;
			cleanup_strings(path_env_paths);
			return (0);
		}
		free(candidate_path);
	}
	cleanup_strings(path_env_paths);
	return (print_error("command not found", 127));
}
