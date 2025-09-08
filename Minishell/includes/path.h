/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:15:43 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/21 13:52:25 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cleanup_strings(char **strings);
t_bool	exists_path(char *path);
int		generate_candidate_path(char *path, char *name, char **dst);
char	**generate_path_env_paths(t_env *env);
int		find_binary_in_path(char *name, char **result_path, t_env *env);
