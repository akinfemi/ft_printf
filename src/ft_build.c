/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 09:22:25 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/26 10:31:09 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>
void	ft_build(va_list ap, t_format *p, t_output **output) {
    char *res;
    t_output *out;
    int len;
    char ch;

    out = *output;
    res = handle_conv(ap, p->conv, p);
    len = ft_strlen(res);
    ch = ' ';
    if (p->minus && p->flag_minus)
        ft_add(ft_padstr('-', 1), output, 1);
    if (p->minus)
        len++;
    if (p->min_width > p->precision && p->precision > 0 && p->flag_minus == 0) {
        ft_add(ft_padstr(ch, p->min_width - p->precision - p->plus), output, 1);
        if (p->minus)
            ft_add(ft_padstr('-', 1), output, 1);
    }
    if (p->min_width > p->precision && p->precision == 0 && p->flag_minus == 0 && p->min_width > len)
    {
        ft_add(ft_padstr(ch, p->min_width - len), output, 1);
        if (p->minus)
            ft_add(ft_padstr('-', 1), output, 1);
    }
    if (p->precision && p->conv != '%' && p->precision > len)
    {
        if (p->conv == 'd' || p->conv == 'i' || p->conv == 'x' || p->conv == 'o' || p->conv == 'u')
            ch = '0';
        ft_add(ft_padstr(ch, p->precision - len), output, 1);
    }
    if (p->plus)
        ft_add(ft_padstr('+', 1), output, 0);
    if (p->minus == 0 && p->space && (p->conv == 'd' || p->conv == 'i'))
        ft_add(ft_padstr(' ', 1), output, 1);
    if (p->conv == 's' && p->precision != 0 && p->precision < len)
        res = ft_strndup(res, p->precision); // memory leak
    ft_add(res, output, 1);
    if (p->flag_minus && p->min_width > len)
        ft_add(ft_padstr(' ', p->min_width - out->len), output, 1);
}

void		ft_add(char *str, t_output **output, int booln) {
    t_output *out;

    out = *output;
    if (booln)
        out->len += ft_strlen(str);
    out->res = ft_strjoin(out->res, str);
}