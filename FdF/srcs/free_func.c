#include "../includes/fdf.h"

void free_fdf(int **fdf, int num)
{
    int i;

    if (num == -1)
        return ;
    i = 0;
    while (i < num)
    {
        free(fdf[i]);
        i++;
    }
    free(fdf);
}

void free_split(char **nums)
{
    int i;

    i = 0;
    while (nums[i])
    {
        free(nums[i]);
        i++;
    }
    free(nums);
}


void free_mlx(t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->data.img);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
}