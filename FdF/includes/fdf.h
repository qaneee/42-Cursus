#ifndef FDF_H
# define FDF_H

#include <math.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

# define PI 3.14159265358979323846
# define ESC_KEY 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define X 120
# define Y 121
# define Z 122
# define R_LEFT 44
# define R_RIGHT 46
# define Q 113
# define W 119
# define E 101
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
} t_point;

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int **fdf;
    int **colors;
    char *input;
    int height;
    int width;
    float offset_x;
    float offset_y;
    float scale;
    t_point a;
    t_point b;
    int x1;
    int y1;
    int needs_update;
    float angle_x;
    float angle_y;
    float angle_z;
    int x_key;
    int y_key;
    int z_key;
    int projection;
    int is_rotating_x;
    int is_rotating_y;
    int is_rotating_z;
} t_data;

typedef struct s_vars
{
    void *mlx;
    void *win;
    t_data data;
} t_vars;

int set_color(int T, int R, int G, int B);
int color_t(int trgb);
int color_r(int trgb);
int color_g(int trgb);
int color_b(int trgb);
int atoi_hex(char *s);
void map_dimensions(t_data *data);
void fill_matrix(t_data *data, char *input);
void input_error(char *msg);
void put_error(t_data *data, int n, int m);
void mlx_error(t_vars *vars);
void free_split(char **nums);
void free_fdf(int **fdf, int num);
void free_mlx(t_vars *vars);
void isometric_projection(t_point *a);
void oblique_projection(t_point *a);
void tpp_projection(t_data *data, t_point *a);
void parallel_projection(t_point *a, int check);
void pick_projection(t_vars *vars, t_point *a);
void rotate_z(t_data *data, t_point *a);
void rotate_y(t_data *data, t_point *a);
void rotate_x(t_data *data, t_point *a);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int get_color(t_data *data);
void bresenham(t_vars *vars);
int draw(t_vars *vars, int i, int j);
void drawing_order(t_vars *vars);
void close_window_esc(t_vars *vars);
int close_window(t_vars *vars);
int mouse_hook(int way, int x, int y, t_vars *vars);
int render_next_frame(t_vars *vars);
int key_hooks(int keycode, t_vars *vars);
int key_releases(int keycode, t_data *data);

#endif