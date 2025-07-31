#include "../includes/fdf.h"

static void slope_more_than_one(int dx, int dy, t_point *a, t_vars *vars)
{
    int p;
    int i;

    i = -1;
    p = 2 * abs(dx) - abs(dy);
    my_mlx_pixel_put(&vars->data, a->x, a->y, get_color(&vars->data));
    while (++i < abs(dy))
    {
        if (dy > 0)
            a->y += 1;
        else
            a->y -= 1;
        if (p < 0)
            p = p + 2 * abs(dx);
        else
        {
            if (dx > 0)
                a->x += 1;
            else
                a->x -= 1;
            p = p + 2 * abs(dx) - 2 * abs(dy);
        }
        my_mlx_pixel_put(&vars->data, a->x, a->y, get_color(&vars->data));
    }
}

static void slope_less_than_one(int dx, int dy, t_point *a, t_vars *vars)
{
    int p;
    int i;

    i = -1;
    p = 2 * abs(dy) - abs(dx);
    my_mlx_pixel_put(&vars->data, a->x, a->y, get_color(&vars->data));
    while (++i < abs(dx))
    {
        if (dx > 0)
            a->x += 1;
        else
            a->x -= 1;
        if (p < 0)
            p = p + 2 * abs(dy);
        else
        {
            if (dy > 0)
                a->y += 1;
            else 
                a->y -= 1;
            p = p + 2 * abs(dy) - 2 * abs(dx);
        }
        my_mlx_pixel_put(&vars->data, a->x, a->y, get_color(&vars->data));
    }
}

void bresenham(t_vars *vars)
{
    int dx;
    int dy;

    dx = vars->data.b.x - vars->data.a.x;
    dy = vars->data.b.y - vars->data.a.y;
    vars->data.x1 = vars->data.a.x;
    vars->data.y1 = vars->data.a.y;
    if (abs(dx) > abs(dy))
        slope_less_than_one(dx, dy, &vars->data.a, vars);
    else
        slope_more_than_one(dx, dy, &vars->data.a, vars);
}