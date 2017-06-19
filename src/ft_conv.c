//
// Created by akinfemi on 5/29/17.
//
#include <ft_printf.h>

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
    else if (arg == 'c')
        return (ft_padstr(va_arg(ap, int), 1));
    else if (arg == '%')
        return (ft_padstr(arg, 1));
    else if (arg == 'o')
        return (ft_itoa_base(ft_oux_len(ap, params), 8));
    else if (arg == 'u')
        return (ft_itoa_base(ft_oux_len(ap, params), 10));
    else if (arg == 'U')
        return (ft_itoa_upper_base(ft_U_len(ap), 10));
    else if (arg == 'x')
        return (ft_itoa_base(ft_oux_len(ap, params), 16));
    else if (arg == 'X')
        return (ft_itoa_upper_base(ft_oux_len(ap, params), 16));
    else if (arg == 'p')
        return (ft_handle_p(ap, params));
    else if (arg == 'D')
    {
        params->lmod = 'l';
        str = ft_imaxtoa(ft_di_len(ap, params));
         if (*str == '-')
         {
             params->minus = 1;
             str++;
         }
        return (str);
    }
    else if (arg == 'O')
    {
        params->lmod = 'l';
        str = ft_itoa_base(ft_oux_len(ap, params), 8);
        return (str);
    }
    return(0);
}

intmax_t    ft_di_len(va_list ap, t_format *params)
{
    if (params->lmod == 'L')  //long long
        return (va_arg(ap, long long));
    else if (params->lmod == 'h')
        return ((short) va_arg(ap, int));
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

uintmax_t   ft_oux_len(va_list ap, t_format *params)
{
    if (params->lmod == 'L')  //long long
        return (va_arg(ap, unsigned long long));
    else if (params->lmod == 'h')
        return ((unsigned short) va_arg(ap, unsigned int));
    else if (params->lmod == 'l')
        return (va_arg(ap, unsigned long));
    else if (params->lmod == 'z')
        return (va_arg(ap, size_t));
    else if (params->lmod == 'j')
        return (va_arg(ap, uintmax_t));
    else if (params->lmod == 'H')
        return ((unsigned char)va_arg(ap, int));
    else
        return (va_arg(ap, unsigned int));
}

uintmax_t   ft_U_len(va_list ap)
{
    return (va_arg(ap, unsigned long));
}