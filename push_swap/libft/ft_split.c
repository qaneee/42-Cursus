#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *) malloc (sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_func(char const **s, int *start, int *end, char *c)
{
	while ((*s)[*end] == *c)
		(*end)++;
	*(start) = *(end);
	while ((*s)[(*end)] && (*s)[(*end)] != *c)
		(*end)++;
}

static void	free_all(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		start;
	int		end;
	int		index;

	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !result)
		return (NULL);
	index = 0;
	end = 0;
	while (s[end])
	{
		ft_func(&s, &start, &end, &c);
		if (start < end)
		{
			result[index] = word_dup(s, start, end);
			if (!result[index])
			{
				free_all(result, index - 1);
				return (NULL);
			}
			index++;
		}
	}
	return (result[index] = NULL, result);
}
