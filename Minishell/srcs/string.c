/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <arvardan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:02:22 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/08 15:03:13 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_string_field(char **field, char *new_value)
{
	char	*new_value_copy;

	new_value_copy = ft_strdup(new_value);
	if (new_value && !new_value_copy)
	{
		return (1);
	}
	if (*field)
	{
		free(*field);
	}
	*field = new_value_copy;
	return (0);
}

void	idk(char **content, char *line)
{
	char	*temp;

	if ((*content)[0])
	{
		temp = ft_strjoin(*content, "\n");
		update_string_field(content, temp);
		free (temp);
	}
	temp = ft_strjoin(*content, line);
	update_string_field(content, temp);
	free (temp);
}
