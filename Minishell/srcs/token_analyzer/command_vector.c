/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:17:21 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/13 22:31:34 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	resize_commands(t_command_vector *v, size_t new_capacity)
{
	size_t		i;
	t_command	*new_data;

	if (new_capacity < v->capacity)
		return (1);
	new_data = malloc(sizeof(*new_data) * new_capacity);
	ft_memset(new_data, 0, sizeof(*new_data) * new_capacity);
	if (!new_data)
		return (1);
	i = 0;
	while (i < v->size)
	{
		copy_command(&(new_data[i]), v->data[i]);
		clear_command(&(v->data[i]));
		++i;
	}
	if (v->data && v->capacity)
		free(v->data);
	v->data = new_data;
	v->capacity = new_capacity;
	return (0);
}

void	init_commands(t_command_vector *v)
{
	v->size = 0;
	v->capacity = 0;
	v->data = 0;
}

void	clear_commands(t_command_vector *v)
{
	size_t	i;

	i = 0;
	while (i < v->size)
	{
		clear_command(&(v->data[i]));
		++i;
	}
	if (v->capacity)
	{
		free(v->data);
	}
	v->size = 0;
	v->capacity = 0;
	v->data = 0;
}

int	push_back_command(t_command_vector *v, t_command command)
{
	if (v->capacity == 0)
	{
		if (resize_commands(v, 1))
		{
			return (1);
		}
	}
	if (v->capacity == v->size)
	{
		if (resize_commands(v, 2 * v->capacity))
		{
			return (1);
		}
	}
	copy_command(&(v->data[v->size]), command);
	++(v->size);
	return (0);
}
