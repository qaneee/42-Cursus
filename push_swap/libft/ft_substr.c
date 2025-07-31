#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *) malloc (len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy (substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
