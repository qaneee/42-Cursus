#include "../includes/fdf.h"

static int valid_base(char *s, char *hexl, char *hexu)
{
    int i;

    i = 0;
    while (hexl[i])
    {
        if (*s == hexl[i] || *s == hexu[i])
            return i;
        i++;
    }
    return (-1);
}

static int convert(char *s, char *hexl, char *hexu)
{
    int result;
    int i;

    result = 0;
    while (*s)
    {
        i = valid_base(s, hexl, hexu);
        if (i == -1)
            return (-1);
        result *= 16;
        result += i;
        s++;
    }
    return (result);
}

int atoi_hex(char *s)
{
    char *hexl;
    char *hexu;

    hexl = "0123456789abcdef";
    hexu = "0123456789ABCDEF";
    if (!s)
        return (-1);
    if (*s == '0')
    {
        s++;
        if (*s == 'x')
            s++;
        else
            return (-1);
    }
    else
        return (-1);
    return (convert(s, hexl, hexu));
}