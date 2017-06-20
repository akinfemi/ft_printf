//
// Created by Akinfemi Akin-Aluko on 6/19/17.
//
#include <ft_printf.h>

int     ft_isox(char c)
{
    return (c == 'x' || c == 'X' || c == 'o' || c == 'O');
}

int     set_len(t_format **params, char *res, int n)
{
    t_format    *p;
    int         len;

    len = n;
    p = *params;
    len = (p->precision > 0) ? p->precision : len;
    len = (p->conv == 's' && p->precision > n) ? n : len;
    len = (ft_is_dioux(p->conv) && p->precision < n) ? n : len;
    len += (p->hash && (p->conv == 'x' || p->conv == 'X')) ? 2 : 0;
    len = (p->conv == 'c' && ft_strlen(res) == 0) ? 1 : len;
    return (len);
}

char    set_ch(t_format **params)
{
    char    ch;
    t_format    *p;

    p = *params;
    ch = (p->zero && p->period == 0) ? '0' : ' ';
    return (ch);
}

char    *ft_handle_p(va_list ap, t_format *params)
{
    char    *str;
    char    *temp;

    (void)params;
    str = ft_itoa_base(va_arg(ap, intmax_t), 16);
    temp = ft_strdup("0x");
    str = ft_strjoin(temp, str);
    free(temp);
    return (str);
}

void    add_prefix(t_format **params, t_output **output, char *res, char ch)
{
    t_format    *p;

    p = *params;
    if (p->hash && ft_tolower(p->conv) == 'x' && p->zero && *res != '0')
        handle_hash(&p, output);
    if (p->minus && ch == '0')
        handle_minus(params, output);
    if (ch == '0' && p->plus)
        handle_plus(params, output);
}
