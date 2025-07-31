#include "../includes/fdf.h"

static void init_fdf(t_data *data, char *input)
{
    data->input = input;
    data->height = 0;
    data->width = -1;
    map_dimensions(data);
    data->scale = (WIDTH + HEIGHT) / (data->width + data->height) * 0.25;
    data->offset_x = WIDTH / 2 - (data->width * data->scale) / 4;
    data->offset_y = HEIGHT / 2 - (data->height * data->scale) / 4;
    data->needs_update = 1;
    data->angle_x = 0;
    data->angle_y = 0;
    data->angle_z = 0;
    data->x_key = 0;
    data->y_key = 0;
    data->z_key = 0;
    data->projection = 0;
    data->is_rotating_x = 0;
    data->is_rotating_y = 0;
    data->is_rotating_z = 0;
    fill_matrix(data, input);
}

static void init_mlx(t_vars *vars, t_data *data)
{
    vars->mlx = mlx_init();
    if (!vars->mlx)
        mlx_error(vars);
    vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF");
    if (!vars->win)
        mlx_error(vars);
    data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
    if (!data->img)
        mlx_error(vars);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    if (!data->addr)
        mlx_error(vars);
}

int main(int argc, char **argv)
{
    t_vars vars;

    if (argc != 2)
    {
        ft_putstr_fd("Error! Has to be typed ./fdf file.fdf\n", 2);
        return (1);
    }
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4))
    {
        ft_putstr_fd("Error! Wrong file format\n", 2);
        return (1);
    }
    init_fdf(&vars.data, argv[1]);
    init_mlx(&vars, &vars.data);
    mlx_hook(vars.win, 2, 1L << 0, key_hooks, &vars);
    mlx_hook(vars.win, 17, 1l << 17, close_window, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_releases, &vars.data);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}