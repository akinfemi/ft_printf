//
// Created by Akinfemi Akin-Aluko on 6/19/17.
//
#include <ft_printf.h>

void    handle_hash(t_format **params, t_output **output)
{
    t_format    *p;

    p = *params;
    if (p->hash)
    {
        if (p->conv == 'x')
            ft_add(ft_strdup("0x"), output, 3);
        else if (p->conv == 'X')
            ft_add(ft_strdup("0X"), output, 3);
        else if (ft_tolower(p->conv) == 'o')
            ft_add(ft_padstr('0', 1), output, 3);
    }
}

void    handle_plus(t_format **params, t_output **output)
{
    t_format    *p;

    p = *params;
    if (p->plus && p->minus == 0 && ft_is_di(p->conv))
        ft_add(ft_padstr('+', 1), output, 3);
}

void    handle_space(t_format **params, t_output **output)
{
    t_format    *p;
    t_output    *out;

    p = *params;
    out = *output;
    if (p->space && ft_is_diox(p->conv) && p->plus == 0 && p->minus == 0)
        ft_add(ft_padstr(' ', 1), output, 3);
}

void    handle_minus(t_format **params, t_output **output)
{
    t_format    *p;

    p = *params;
    if (p->minus)
        ft_add(ft_padstr('-', 1), output, 3);
}

uintmax_t   ft_U_len(va_list ap)
{
    return (va_arg(ap, unsigned long));
}