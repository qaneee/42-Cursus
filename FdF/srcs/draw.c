#include "../includes/fdf.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *start;

    if (x <= 0 || x >= WIDTH || y <= 0 || y >= HEIGHT)
        return;
    start = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)start = color;
}

static void clear(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            my_mlx_pixel_put(&vars->data, j, i, set_color(1, 0, 0, 0));
            j++;
        }
        i++;
    }
}

static void set_point(t_vars *vars, t_point *a, int i, int j)
{
    a->color = vars->data.colors[j][i];
    a->x = i;
    a->y = j;
    a->z = vars->data.fdf[j][i];
    a->x *= vars->data.scale;
    a->y *= vars->data.scale;
    a->z *= vars->data.scale;
    rotate_x(&vars->data, a);
    rotate_y(&vars->data, a);
    rotate_z(&vars->data, a);
    pick_projection(vars, a);
    a->x += vars->data.offset_x;
    a->y += vars->data.offset_y;
}

static int in_window(t_point *a, t_point *b)
{
    if ((a->x <= 0 || a->x >= WIDTH || a->y <= 0 || a->y >= HEIGHT)
        && (b->x <= 0 || b->x >= WIDTH || b->y <= 0 || b->y >= HEIGHT))
            return (1);
    return (0);
}

int	draw(t_vars *vars, int i, int j)
{
    clear(vars);
    while (++i < vars->data.width)
    {
        j = -1;
        while (++j < vars->data.height)
        {
            if (i + 1 < vars->data.width)
            {
                set_point(vars, &vars->data.a, i, j);
                set_point(vars, &vars->data.b, i + 1, j);
                if (!in_window(&vars->data.a, &vars->data.b))
                    bresenham(vars);
            }
            if (j + 1 < vars->data.height)
            {
                set_point(vars, &vars->data.a, i, j);
                set_point(vars, &vars->data.b, i, j + 1);
                if(!in_window(&vars->data.a, &vars->data.b))
                    bresenham(vars);
            }
        }
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
    return (0);
}