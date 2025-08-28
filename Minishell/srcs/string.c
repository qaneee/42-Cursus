/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:48:37 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/13 23:49:20 by ipogodae         ###   ########.fr       */
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
