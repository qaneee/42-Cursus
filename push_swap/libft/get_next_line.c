#include "libft.h"

static char	*join_buffer(char *buffer, char *temp)
{
	char	*new_buffer;

	if (!buffer)
		return (gnl_ft_strdup(temp));
	new_buffer = gnl_ft_strjoin(buffer, temp);
	free(buffer);
	return (new_buffer);
}

static char	*read_file(int fd, char *buffer)
{
	char	*temp;
	ssize_t	count;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free(buffer), NULL);
	count = read(fd, temp, BUFFER_SIZE);
	while (count > 0)
	{
		temp[count] = '\0';
		buffer = join_buffer(buffer, temp);
		if (!buffer)
			return (free(temp), NULL);
		if (!buffer || gnl_ft_strchr(buffer, '\n'))
			break ;
		count = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	if (count < 0)
		return (free(buffer), NULL);
	return (buffer);
}

static char	*get_line(char *s)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!s || !s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		line = malloc(i + 1);
	else
		line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*free_s(char *s)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i++])
		return (free(s), NULL);
	new = malloc(gnl_ft_strlen(s + i) + 1);
	if (!new)
		return (free(s), NULL);
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	free(s);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1)
		return (free(buffer), buffer = NULL, NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	if (!gnl_ft_strchr(buffer, '\n'))
	{
		line = get_line(buffer);
		return (free(buffer), buffer = NULL, line);
	}
	line = get_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = free_s(buffer);
	return (line);
}
