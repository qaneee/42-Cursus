#include "../includes/fdf.h"

static void key_hooks_rotation(int keycode, t_vars *vars)
{
    float d;

    if (keycode == R_LEFT || keycode == R_RIGHT)
    {
        if (keycode == R_LEFT)
            d = 0.1;
        else
            d = -0.1;
        if (vars->data.x_key == 1)
        {
            vars->data.angle_x +=d;
            vars->data.needs_update = 1;
        }
        else if (vars->data.y_key == 1)
        {
            vars->data.angle_y +=d;
            vars->data.needs_update = 1;
        }
        else if (vars->data.z_key == 1)
        {
            vars->data.angle_z += d;
            vars->data.needs_update = 1;
        }
    }
}

static void key_hooks_projection(int keycode, t_vars *vars)
{
    if (keycode >= 48 && keycode <= 53)
    {
        if (keycode == 48)
            vars->data.projection = 0;
        else if (keycode == 49)
            vars->data.projection = 1;
        else if (keycode == 50)
            vars->data.projection = 2;
        else if (keycode == 51)
			vars->data.projection = 3;
		else if (keycode == 52)
			vars->data.projection = 4;
		else if (keycode == 53)
			vars->data.projection = 5;
        vars->data.needs_update = 1;
        vars->data.angle_x = 0;
        vars->data.angle_y = 0;
        vars->data.angle_z = 0;
    }
}

static void auto_rotation(int keycode, t_vars *vars)
{
    if (keycode == 113)
    {
        vars->data.is_rotating_x = !vars->data.is_rotating_x;
        vars->data.is_rotating_y = 0;
        vars->data.is_rotating_z = 0;
    }
    else if (keycode == 119)
    {
        vars->data.is_rotating_y = !vars->data.is_rotating_y;
        vars->data.is_rotating_x = 0;
        vars->data.is_rotating_z = 0;
    }
    else if (keycode == 101)
    {
        vars->data.is_rotating_z = !vars->data.is_rotating_z;
        vars->data.is_rotating_x = 0;
        vars->data.is_rotating_y = 0;
    }
}

int key_hooks(int keycode, t_vars *vars)
{
    key_hooks_rotation(keycode, vars);
    key_hooks_projection(keycode, vars);
    auto_rotation(keycode, vars);
    if (keycode == ESC_KEY)
        close_window_esc(vars);
    else if (keycode == LEFT)
        vars->data.offset_x -= 10;
    else if (keycode == RIGHT)
        vars->data.offset_x += 10;
    else if (keycode == UP)
        vars->data.offset_y -= 10;
    else if (keycode == DOWN)
        vars->data.offset_y += 10;
    else if (keycode == X)
        vars->data.x_key = 1;
    else if (keycode == Y)
        vars->data.y_key = 1;
    else if (keycode == Z)
        vars->data.z_key = 1;
    vars->data.needs_update = 1;
    return (0);
}

int key_releases(int keycode, t_data *data)
{
    if (keycode == 120)
        data->x_key = 0;
    else if (keycode == 121)
        data->y_key = 0;
    else if (keycode == 122)
        data->z_key = 0;
    return (0);
}