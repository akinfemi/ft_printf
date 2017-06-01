//
// Created by Akinfemi Akin-Aluko on 5/31/17.
//

#include <ft_printf.h>

//void    handle_hash(t_format **p, t_output **output)
//{
//
//}

void    handle_plus(t_format **params, t_output **output)
{
    t_format    *p;

    p = *params;
    if (p->plus && p->minus == 0)
        ft_add(ft_padstr('+', 1), output, 1);
}

void    handle_zero(char *ch, t_format **params)
{
    t_format    *p;

    p = *params;
    *ch = (p->zero && ft_is_dioux(p->conv)) ? '0' : ' ';
}

void    handle_space(t_format **params, t_output **output)
{
    t_format    *p;
    t_output    *out;

    p = *params;
    out = *output;
    if (p->space && ft_is_dioux(p->conv) && p->plus == 0)
        ft_add(ft_padstr(' ', 1), output, 1);
}

void    handle_padding(t_format **params, t_output **output, int len)
{
    t_format    *p;

    p = *params;
    len = (p->precision > 0) ? p->precision : len;
    if (p->min_width > p->precision && p->flag_minus == 0) {
        ft_add(ft_padstr(' ', p->min_width - p->plus - p->minus - len), output, 1);
    }
//    if (p->min_width >= p->precision && p->precision == 0 && p->flag_minus == 0)
//    {
//        ch = (p->zero && ft_is_dioux(p->conv)) ? '0' : ' ';
//        if(p->min_width > len)
//            ft_add(ft_padstr(ch, p->min_width - len), output, 1);
//    }
}

void    handle_minus(t_format **params, t_output **output)
{
    t_format    *p;

    p = *params;
    if (p->minus)
        ft_add(ft_padstr('-', 1), output, 1);
}

void    handle_precision(t_format **params, t_output **output, int len)
{
    t_format    *p;
    char        ch;

    p = *params;
    if (p->precision && p->conv != '%' && p->precision > len)
    {
        ch = (ft_is_dioux(p->conv)) ? '0' : ' ';
        ft_add(ft_padstr(ch, p->precision - len), output, 1);
    }
}

void    handle_res(char *res, t_output **output)
{
    ft_add(res, output, 1);
}

void    handle_alignment(t_format **params, t_output **output, int len)
{
    t_format    *p;
    t_output    *out;

    p = *params;
    out = *output;
    if (p->flag_minus && p->min_width > len) //nts: you are comparing len but subtracting out-len!!!
        ft_add(ft_padstr(' ', p->min_width - out->len), output, 1);
}