/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:28:12 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/01 14:15:13 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			k;
	unsigned char	*p;

	k = 0;
	p = (unsigned char *)b;
	while (len--)
	{
		*(p + k) = (unsigned char)c;
		k++;
	}
	return (b);
}
