/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:43:03 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/13 17:00:06 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	resize_string(t_char_vector *v, size_t new_capacity)
{
	size_t	i;
	char	*new_data;

	if (new_capacity == 0)
		return (resize_string(v, 1));
	if (new_capacity < v->capacity)
		return (1);
	new_data = malloc(sizeof(*new_data) * new_capacity);
	ft_memset(new_data, 0, sizeof(*new_data) * new_capacity);
	if (!new_data)
		return (1);
	i = 0;
	while (i < v->size)
	{
		new_data[i] = v->data[i];
		++i;
	}
	new_data[i] = 0;
	if (v->data && v->capacity)
		free(v->data);
	v->data = new_data;
	v->capacity = new_capacity;
	return (0);
}

void	init_string(t_char_vector *v)
{
	v->size = 0;
	v->capacity = 0;
	v->data = 0;
	resize_string(v, 0);
}

void	clear_string(t_char_vector *v)
{
	if (!v)
	{
		return ;
	}
	if (v->data)
	{
		free(v->data);
	}
	v->size = 0;
	v->capacity = 0;
	v->data = 0;
}

int	push_back_char(t_char_vector *v, char c)
{
	if (v->capacity == 0)
	{
		if (resize_string(v, 1))
		{
			return (1);
		}
	}
	if (v->capacity == v->size + 1)
	{
		if (resize_string(v, 2 * v->capacity))
		{
			return (1);
		}
	}
	v->data[v->size] = c;
	++(v->size);
	v->data[v->size] = 0;
	return (0);
}

void	copy_string(t_char_vector *dst, t_char_vector src)
{
	size_t	i;

	clear_string(dst);
	i = 0;
	while (i != src.size)
	{
		push_back_char(dst, src.data[i]);
	}
}
