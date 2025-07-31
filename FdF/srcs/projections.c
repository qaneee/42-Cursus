#include "../includes/fdf.h"

void isometric_projection(t_point *a)
{
    int temp;
    // maybe will need casting (double -> int)
    temp = a->x;
    a->x = (a->x - a->y) * cos(PI / 6);
    a->y = (temp + a->y) * sin(PI / 6) - a->z;
}

void oblique_projection(t_point *a)
{
    a->x = a->x + a->z / 2 * cos(PI / 4);
    a->y = a->y + a->z / 2 * sin(PI / 4);
}

void tpp_projection(t_data *data, t_point *a)
{
    int depth;

    depth = (data->width + data->height) / 2 * 100;
    a->x = a->x * depth / (-a->z + depth + 1e-10);
    a->y = a->y * depth / (-a->z + depth + 1e-10);
}

void parallel_projection(t_point *a, int check)
{
    if (check == 1)
        a->x = a->z;
    else if (check == 2)
        a->y = a->z;
}

void pick_projection(t_vars *vars, t_point *a)
{
    if (vars->data.projection == 1)
        parallel_projection(a, 1);
    else if (vars->data.projection == 2)
        parallel_projection(a, 2);
    else if (vars->data.projection == 3)
        parallel_projection(a, 0);
    else if (vars->data.projection == 4)
        tpp_projection(&vars->data, a);
    else if (vars->data.projection == 5)
        oblique_projection(a);
    else
        isometric_projection(a);
}