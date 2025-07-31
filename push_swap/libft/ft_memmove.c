#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	if (*d < *s || *d > *s + len)
		ft_memcpy(d, s, len);
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
