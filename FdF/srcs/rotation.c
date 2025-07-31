#include "../includes/fdf.h"

void rotate_z(t_data *data, t_point *a)
{
    int temp_x;
    int temp_y;

    temp_x = a->x - data->width * data->scale / 2;
    temp_y = a->y - data->height * data->scale / 2;
    a->x = temp_x * cos(data->angle_z) - temp_y * sin(data->angle_z);
    a->y = temp_x * sin(data->angle_z) + temp_y * cos(data->angle_z);
    a->x += data->width * data->scale / 2;
    a->y += data->height * data->scale / 2;
}

void rotate_y(t_data *data, t_point *a)
{
    int temp_x;

    temp_x = a->x - data->width * data->scale / 2;
    a->x = temp_x * cos(data->angle_y) + a->z * sin(data->angle_y);
    a->z = a->z * cos(data->angle_y) - temp_x * sin(data->angle_y);
    a->x += data->width * data->scale / 2;
}

void rotate_x(t_data *data, t_point *a)
{
    int temp_y;

    temp_y = a->y - data->height * data->scale / 2;
    a->y = temp_y * cos(data->angle_x) - a->z * sin(data->angle_x);
    a->z = temp_y * sin(data->angle_x) + a->z * cos(data->angle_x);
    a->y += data->height * data->scale / 2;
}