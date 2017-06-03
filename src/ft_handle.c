//
// Created by Akinfemi Akin-Aluko on 5/31/17.
//

#include <ft_printf.h>
//#include <stdio.h>
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
        else if (p->conv == 'o')
            ft_add(ft_padstr('0', 1), output, 1);
    }
}

void    handle_plus(t_format **params, t_output **output)
{
    t_format    *p;

    p = *params;
    if (p->plus && p->minus == 0 && ft_is_di(p->conv))
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
    int         n;

    p = *params;
    n = ft_strlen(res);
    sign = (p->plus || p->minus) ? 1 : 0;
    len = (p->precision > 0) ? p->precision : len;
    len = (p->conv == 's' && p->precision > n) ? n : len;
    len = (ft_is_dioux(p->conv) && p->precision < n) ? n : len;
    len += (p->hash && (p->conv == 'x' || p->conv == 'X')) ? 2 : 0;
    len = (p->conv == 'c' && ft_strlen(res) == 0) ? 1 : len;
    ch = (p->zero && ft_is_dioux(p->conv) && p->precision == 0) ? '0' : ' ';
    if (p->hash && (p->conv == 'x' || p->conv == 'X') && p->zero && *res != '0')
        handle_hash(&p, output);
    if (p->minus && ch == '0')
        handle_minus(params, output);
    if (ch == '0' && p->plus)
        handle_plus(params, output);
    if (p->min_width > p->precision && p->flag_minus == 0)
        ft_add(ft_padstr(ch, p->min_width - sign - len - p->space - (p->hash && p->conv == 'o')), output, 1);
    if (p->hash && (p->conv == 'x' || p->conv == 'X' || p->conv == 'o') && p->zero == 0 && *res != '0')
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
    if (!res && p->conv == 's')
        res = "(null)";
    else if (p->conv == 's' && p->precision != 0 && p->precision < len) //truncate string
        res = ft_strndup(res, p->precision); // nts: fix memory leak
    else if (res && *res == '0' && ft_is_dioux(p->conv) && p->period == 1)
    {
        *res = '\0';
        if (p->hash && p->conv == 'o')
            *res = '0';
        if (p->min_width > 0)
            *res = ' ';
        if (ft_is_dioux(p->conv) && p->precision > 1)
            *res = '0';
    }
    ft_add(res, output, 1);
    if (ft_strlen(res) == 0 && p->conv == 'c')
        ft_add(res, output, 2);
}

void    handle_alignment(t_format **params, t_output **output)
{
    t_format    *p;
    t_output    *out;

    p = *params;
    out = *output;
//    printf("Len: %d\n", len);
//    printf("Out->len: %d\n", out->len);
//    printf("p->width: %d\n", p->min_width);
//    printf("p->precision: %d\n", p->precision);
    if (p->flag_minus && p->min_width > out->len) {
        ft_add(ft_padstr(' ', p->min_width - out->len), output, 1);
//        printf("Out->len: %d\n", out->len);
    }
//    if (p->conv == 'c' && )
}