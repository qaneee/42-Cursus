#include "../includes/fdf.h"

int set_color(int T, int R, int G, int B)
{
    return (T << 24 | R << 16 | G << 8 | B);
}

int color_t(int trgb)
{
    return ((trgb >> 24) & 0xFF);
}

int color_r(int trgb)
{
    return ((trgb >> 16) & 0xFF);
}

int color_g(int trgb)
{
    return ((trgb >> 8) & 0xFF);
}

int color_b(int trgb)
{
    return (trgb & 0xFF);
}
