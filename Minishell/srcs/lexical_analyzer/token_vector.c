/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:49:27 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/14 00:01:50 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	resize_tokens(t_token_vector *v, size_t new_capacity)
{
	size_t	i;
	t_token	*new_data;

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
	if (v->data && v->capacity)
		free(v->data);
	v->data = new_data;
	v->capacity = new_capacity;
	return (0);
}

void	init_tokens(t_token_vector *v)
{
	v->size = 0;
	v->capacity = 0;
	v->data = 0;
}

void	clear_tokens(t_token_vector *v)
{
	size_t	i;

	if (!v)
	{
		return ;
	}
	if (!v->size)
	{
		return ;
	}
	i = 0;
	while (i < v->size)
	{
		clear_token(&(v->data[i]));
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

int	push_back_token(t_token_vector *v, t_token_type type, char *value)
{
	if (v->capacity == 0)
	{
		if (resize_tokens(v, 1))
		{
			return (1);
		}
	}
	if (v->capacity == v->size)
	{
		if (resize_tokens(v, 2 * v->capacity))
		{
			return (1);
		}
	}
	init_token(&(v->data[v->size]));
	v->data[v->size].type = type;
	if (update_string_field(&(v->data[v->size].value), value))
	{
		return (1);
	}
	++(v->size);
	return (0);
}

int	copy_tokens(t_token_vector *dst, t_token_vector src)
{
	size_t	i;

	clear_tokens(dst);
	i = 0;
	while (i != src.size)
	{
		if (push_back_token(dst, src.data[i].type, src.data[i].value))
		{
			return (1);
		}
		++i;
	}
	return (0);
}
