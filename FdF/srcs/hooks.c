#include "../includes/fdf.h"

int mouse_hook(int way, int x, int y, t_vars *vars)
{
    float image_x;
    float image_y;

    image_x = (x - vars->data.offset_x) / vars->data.scale;
    image_y = (y - vars->data.offset_y) / vars->data.scale;
    if (way == MOUSE_SCROLL_UP)
    {
        if (vars->data.scale < 100)
            vars->data.scale *= 1.05;
    }
    else if (way == MOUSE_SCROLL_DOWN)
    {
        if (vars->data.scale > 1)
            vars->data.scale /= 1.05;
    }
    vars->data.offset_x = x - image_x * vars->data.scale;
    vars->data.offset_y = y - image_y * vars->data.scale;
    vars->data.needs_update = 1;
    return (0);
}

// name change might occur

int render_next_frame(t_vars *vars)
{
    if (vars->data.is_rotating_x == 1)
    {
        vars->data.angle_x += 0.01;
        draw(vars, -1, -1);
    }
    if (vars->data.is_rotating_y == 1)
    {
         vars->data.angle_y += 0.01;
        draw(vars, -1, -1);
    }
    if (vars->data.is_rotating_z == 1)
    {
         vars->data.angle_z += 0.01;
        draw(vars, -1, -1);
    }
    if (vars->data.needs_update == 1)
    {
        draw(vars, -1, -1);
        vars->data.needs_update = 0;
    }
    drawing_order(vars);
    return (0);
}