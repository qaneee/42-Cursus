#include "../includes/fdf.h"

static void set_nbr_color(t_data *data, char **nums, int i, int j)
{
    char **nbr_color;
    int color;

    while (++j < data->width)
    {
        ((data->fdf))[i][j] = ft_atoi(nums[j]);
        nbr_color = ft_split(nums[j], ',');
        if (!nbr_color)
            put_error(data, i + 1, i + 1);
        (data->fdf)[i][j] = ft_atoi(nbr_color[0]);
        if (nbr_color[1] && ft_strchr(nbr_color[1], '\n'))
            *ft_strchr(nbr_color[1], '\n') = '\0';
        color = atoi_hex(nbr_color[1]);
        if (color == -1)
        {
            if (data->fdf[i][j] != 0)
                ((data->colors))[i][j] = set_color(1, 0, 250, 250);
            else
                ((data->colors))[i][j] = set_color(1, 0, 150, 150);
        }
        else
            ((data->colors))[i][j] = color;
        free_split(nbr_color);                                             
    }
}

static void fill_helper(t_data *data, int fd)
{
    char **nums;
    char *line;
    int i;

    i = -1;
    while (++i < data->height)
    {
        (data->fdf)[i] = (int *)malloc(data->width * sizeof(int));
        if (!((data->fdf)[i]))
            put_error(data, i, i);
        (data->colors)[i] = (int *)malloc(data->width * sizeof(int));
        if (!((data->colors)[i]))
            put_error(data, i + 1, i);
        line = get_next_line(fd);
        if (!line)
            put_error(data, i + 1, i + 1);
        nums = ft_split(line, ' ');
        if (!nums)
            put_error(data, i + 1, i + 1);
        set_nbr_color(data, nums, i, -1);
        free(line);
        free_split(nums);
    }
    get_next_line(-1);
}

void fill_matrix(t_data *data, char *input)
{
    int fd;

    if (data->height == 0 || data->width == 0)
        exit(0);
    fd = open(input, O_RDONLY);
    if (fd == -1)
        put_error(data, -1, -1);
    data->fdf = (int **)malloc(data->height * sizeof(int *));
    if (!(data->fdf))
        put_error(data, -1, -1);
    data->colors = (int **)malloc(data->height * sizeof(int *));
    if (!(data->colors))
        put_error(data, 0, -1);
    fill_helper(data, fd);
    if (close(fd) == -1)
        put_error(data, 0, 0);
}