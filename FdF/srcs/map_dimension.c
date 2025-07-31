#include "../includes/fdf.h"

static int count_words(char *line)
{
    char **line_content;
    int i;
    int count;

    if (!line)
        return 0;
    line_content = ft_split(line, ' ');
    if (!line_content)
    {
        free(line);
        input_error("Input error");
    }
    i = 0;
    count = 0;
    while (line_content[i])
    {
        if (ft_strncmp(line_content[i], "\n", 1))
            count++;
        i++;
    }
    free_split(line_content);
    return count;
}

static void map_dim_helper(t_data *data, int fd)
{
    char *line;
    
    line = get_next_line(fd);
    if (errno)
        input_error("Input Error");
    while (line)
    {
        data->height++;
        if (data->width == -1)
            data->width = count_words(line);
        else if (data->width != count_words(line))
        {
            ft_putstr_fd("INPUT: File is not valid\n", 2);
            free(line);
            exit(1);
        }
        free(line);
        line = get_next_line(fd);
        if (errno)
            input_error("Input Error");
    }
}

void map_dimensions(t_data *data)
{
    int fd;

    fd = open(data->input, O_RDONLY);
    if (fd == -1)
        input_error("Input error while opening file");
    map_dim_helper(data, fd);
    if (close(fd) == -1)
        input_error("Input error while closing file");
}
