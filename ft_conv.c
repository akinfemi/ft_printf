//
// Created by akinfemi on 5/29/17.
//
#include "ft_printf.h"

char        *handle_conv(va_list ap, char arg)
{
    char    *c;

    c = (char *)ft_memalloc(sizeof(char)*2);
    if (arg == 'd' || arg == 'i')
        return (ft_itoa(va_arg(ap, int)));
    else if (arg == 's')
        return (va_arg(ap, char *));
    else if (arg == 'c') //there's gotta be a better way to do this
    {
        c[0] = va_arg(ap, int);
        c[1] = '\0';
        return (c);
    }
    else if (arg == 'u')
        return (ft_itoa(va_arg(ap, unsigned int)));
//    else if (arg == 'S')
}