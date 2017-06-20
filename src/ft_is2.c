//
// Created by Akinfemi Akin-Aluko on 6/19/17.
//
#include <ft_printf.h>

int		ft_is_dioux(char c)
{
    char	*conv;
    conv = "DdioOuxX";

    while(*conv)
    {
        if (c == *conv)
            return (1);
        conv++;
    }
    return (0);
}

int		ft_is_diox(char c)
{
    char	*conv;
    conv = "DdioOxX";

    while(*conv)
    {
        if (c == *conv)
            return (1);
        conv++;
    }
    return (0);
}

int		ft_is_di(char c)
{
    char	*conv;
    conv = "Ddi";

    while(*conv)
    {
        if (c == *conv)
            return (1);
        conv++;
    }
    return (0);
}
