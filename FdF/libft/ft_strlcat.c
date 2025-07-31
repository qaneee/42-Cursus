/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:17:14 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/01 14:21:06 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (i < dstsize && dst[i])
		i++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	while ((i + k + 1) < dstsize && src[k])
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i != dstsize)
		dst [i + k] = '\0';
	return (i + ft_strlen(src));
}
