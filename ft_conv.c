//
// Created by akinfemi on 5/29/17.
//
#include "ft_printf.h"

char        *handle_conv(va_list ap, char arg)
{
    if (arg == 'd')
    {
        return (ft_itoa(va_arg(ap, int)));
    }
}