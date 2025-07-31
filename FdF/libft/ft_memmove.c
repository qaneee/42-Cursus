/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:40:39 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/01 14:14:33 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr2 > ptr1)
	{
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	else if (ptr2 < ptr1)
	{
		while (len > 0)
		{
			len--;
			ptr1[len] = ptr2[len];
		}
	}
	return (dst);
}
