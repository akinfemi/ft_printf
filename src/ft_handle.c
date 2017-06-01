//
// Created by Akinfemi Akin-Aluko on 5/31/17.
//

#include <ft_printf.h>
#include <stdio.h>
void    handle_hash(t_format **params, t_output **output)
{
    t_format    *p;

    p = *params;
    if (p->hash)
    {
        if (p->conv == 'x')
            ft_add("0x", output, 1);
        else if (p->conv == 'X')
            ft_add("0X", output, 1);
    }
}

void    handle_plus(t_format **params, t_output **output)
{
    t_format    *p;

    p = *params;
    if (p->plus && p->minus == 0 && ft_is_diox(p->conv))
        ft_add(ft_padstr('+', 1), output, 1);
}

void    handle_space(t_format **params, t_output **output)
{
    t_format    *p;
    t_output    *out;

    p = *params;
    out = *output;
    if (p->space && ft_is_diox(p->conv) && p->plus == 0 && p->minus == 0)
        ft_add(ft_padstr(' ', 1), output, 1);
}

void    handle_padding(t_format **params, t_output **output, char *res, int len)
{
    t_format    *p;
    char        ch;
    int         sign;

    p = *params;
    sign = (p->plus || p->minus) ? 1 : 0;
    len = (p->precision > 0) ? p->precision : len;
    len = (p->conv == 's' && p->precision > (int)ft_strlen(res)) ? ft_strlen(res) : len;
    len += (p->hash && (p->conv == 'x' || p->conv == 'X')) ? 2 : 0;
    ch = (p->zero && ft_is_dioux(p->conv) && p->precision == 0) ? '0' : ' ';
    if (p->hash && (p->conv == 'x' || p->conv == 'X') && p->zero && *res != '0')
        handle_hash(&p, output);
    if (p->minus && ch == '0')
        handle_minus(params, output);
    if (ch == '0' && p->plus)
        handle_plus(params, output);
    if (p->min_width > p->precision && p->flag_minus == 0)
        ft_add(ft_padstr(ch, p->min_width - sign - len - p->space), output, 1);
    if (p->hash && (p->conv == 'x' || p->conv == 'X') && p->zero == 0 && *res != '0')
        handle_hash(&p, output);
    if (p->minus && ch == ' ')
        handle_minus(params, output);
    if (ch == ' ' && p->plus)
        handle_plus(params, output);
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
    if (p->precision && ft_is_dioux(p->conv) && p->precision > len)
    {
        ch = (ft_is_dioux(p->conv)) ? '0' : ' ';
        ft_add(ft_padstr(ch, p->precision - len), output, 1);
    }
}

void    handle_res(t_format **params, t_output **output, char *res, int len)
{
    t_format    *p;

    p = *params;
    if (p->conv == 's' && p->precision != 0 && p->precision < len) //truncate string
        res = ft_strndup(res, p->precision); // nts: fix memory leak!
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