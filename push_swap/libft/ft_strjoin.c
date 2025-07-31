#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *) malloc (len1 + len2 + 1);
	if (!result)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	ft_memcpy (result, s1, len1);
	ft_memcpy (result + len1, s2, len2);
	result [len1 + len2] = '\0';
	return (result);
}
