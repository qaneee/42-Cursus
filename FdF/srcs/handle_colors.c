#include "../includes/fdf.h"

static float calc_fraction(float x1, float x2, float x)
{
    if (x1 != x2)
        return ((x - x1) / (x2 - x1));
    return (0);
}

static float choose_fraction(t_point *a, t_point *b, int x, int y)
{
    int dx;
    int dy;
    float fraction;

    dx = b->x - a->x;
    dy = b->y - a->y;
    if (abs(dx) > abs(dy))
        fraction = calc_fraction(x, b->x, a->x); // (a->x, b->x, x);  
    else
        fraction = calc_fraction(y, b->y, a->y); // (a-y, b->y, y);
    return (fraction);
}

int get_color(t_data *data)
{
    int red;
    int green;
    int blue;
    float fraction;

    if (data->a.color == data->b.color)
        return (data->a.color);
    fraction = choose_fraction(&data->a, &data->b, data->x1, data->y1);
    red = color_r(data->a.color) + (color_r(data->b.color) - color_r(data->a.color)) * fraction;
    green = color_g(data->a.color) + (color_g(data->b.color) - color_g(data->a.color)) * fraction;
    blue = color_b(data->a.color) + (color_b(data->b.color) - color_b(data->a.color)) * fraction;
    return (set_color(0, red, green, blue));
}