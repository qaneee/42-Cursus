#include "../includes/fdf.h"

void input_error(char *msg)
{
    perror(msg);
    exit(1);
}

void put_error(t_data *data, int n, int m)
{
    free_fdf(data->fdf, n);
    free_fdf(data->colors, m);
    perror("FDF");
    exit(1);
}

void mlx_error(t_vars *vars)
{
    if (!vars->mlx)
        put_error(&vars->data, vars->data.height, vars->data.height);
    else if (!vars->win)
    {
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
        put_error(&vars->data, vars->data.height, vars->data.height);
    }
    else if (!vars->data.img)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
        put_error(&vars->data, vars->data.height, vars->data.height);
    }
    else if (!vars->data.addr)
    {
        mlx_destroy_image(vars->mlx, vars->data.img);
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
        put_error(&vars->data, vars->data.height, vars->data.height);
    }
}