#include "../includes/fdf.h"

void drawing_order(t_vars *vars)
{
    mlx_string_put(vars->mlx, vars->win, 5, 80, 0xFFFFFF, "Isometric Projection: Key 0");
    mlx_string_put(vars->mlx, vars->win, 5, 60, 0xFFFFFF, "Parallel Projection: Keys 1,2,3");
    mlx_string_put(vars->mlx, vars->win, 5, 120, 0xFFFFFF, "TPP Projection: Key 4");
    mlx_string_put(vars->mlx, vars->win, 5, 100, 0xFFFFFF, "Oblique Projection: Key 5");
    mlx_string_put(vars->mlx, vars->win, 5, 20, 0xFFFFFF, "Translate: Arrow Keys");
    mlx_string_put(vars->mlx, vars->win, 5, 40, 0xFFFFFF, "Zoom: Mouse Scroll up/down");
    mlx_string_put(vars->mlx, vars->win, 5, 140, 0xFFFFFF, "Rotations: x / y / z + < / >");
    mlx_string_put(vars->mlx, vars->win, 5, 160, 0xFFFFFF, "Auto Rotations: q / w / e");
    mlx_string_put(vars->mlx, vars->win, 5, 180, 0xFFFFFF, "Exit: ESC Key");
}

void close_window_esc(t_vars *vars)
{
    free_mlx(vars);
    free_fdf(vars->data.fdf, vars->data.height);
    free_fdf(vars->data.colors, vars->data.height);
    exit(0);
}

int close_window(t_vars *vars)
{
    free_mlx(vars);
	free_fdf(vars->data.fdf, vars->data.height);
	free_fdf(vars->data.colors, vars->data.height);
	exit(0);
}