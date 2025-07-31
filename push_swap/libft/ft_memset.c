#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*b;

	b = (unsigned char *) ptr;
	while (len--)
		*b++ = (unsigned char) c;
	return (ptr);
}
