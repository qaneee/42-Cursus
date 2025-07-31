#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	cc;

	ss = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n > 0)
	{
		if (*ss == cc)
			return ((void *)ss);
		ss++;
		n--;
	}
	return (NULL);
}
