/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:07:01 by arvardan          #+#    #+#             */
/*   Updated: 2025/02/15 20:33:49 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, int n)
{
	while (n > 0)
	{
		free(str[n - 1]);
		n--;
	}
	free(str);
	return (0);
}

static int	ft_word_count(char const *ptr, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			i++;
		else
		{
			count++;
			while (ptr[i] && ptr[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_copy_word(char *word, char const *s, int start, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[start];
		j++;
		start++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_words_split(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		word_len = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(word_len + 1);
		if (!s2[word])
			return (ft_free(s2, word));
		ft_copy_word(s2[word], s, i - word_len, word_len);
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	size_t	num_words;

	if (!s)
		return (NULL);
	num_words = ft_word_count(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (NULL);
	return (ft_words_split(s, c, s2, num_words));
}
