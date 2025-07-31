#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (!d && !s)
		return (NULL);
	while (len--)
		*d++ = *s++;
	return (dst);
}
