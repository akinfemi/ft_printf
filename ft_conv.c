//
// Created by akinfemi on 5/29/17.
//
#include "ft_printf.h"

char        *handle_conv(va_list ap, char arg, t_format *params)
{
    char    *str;
    if (arg == 'd' || arg == 'i')
    {
        str = ft_imaxtoa(ft_di_len(ap, params));
        if (*str == '-')
        {
            params->minus = 1;
            str++;
        }
        return (str);
    }
    else if (arg == 's')
        return (va_arg(ap, char *));
    else if (arg == 'c') //there's gotta be a better way to do this
        return (ft_ctostr(va_arg(ap, int)));
    else if (arg == '%')
        return (ft_ctostr(arg));
    return(0);
//    else if (arg == 'S')
}

intmax_t    ft_di_len(va_list ap, t_format *params)
{
    if (params->lmod == 'L')  //long long
        return (va_arg(ap, long long));
    else if (params->lmod == 'h')
        return ((short) va_arg(ap, unsigned int));
    else if (params->lmod == 'l')
        return (va_arg(ap, long));
    else if (params->lmod == 'z')
        return (va_arg(ap, size_t));
    else if (params->lmod == 'j')
        return (va_arg(ap, intmax_t));
    else if (params->lmod == 'H')
        return ((char)va_arg(ap, unsigned int));
    else
        return (va_arg(ap, int));
}