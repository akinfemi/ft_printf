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

#include "ft_printf.h"

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
        ft_add(ft_ctostr('-'), output);
    if (p->minus)
        len++;
    if (p->min_width > p->precision && p->precision > 0 && p->flag_minus == 0) {
        ft_add(ft_padstr(ch, p->min_width - p->precision), output);
        if (p->minus)
            ft_add(ft_ctostr('-'), output);
    }
    if (p->min_width > p->precision && p->precision == 0 && p->flag_minus == 0)
    {
        ft_add(ft_padstr(ch, p->min_width - len), output);
        if (p->minus)
            ft_add(ft_ctostr('-'), output);
    }
    if (p->precision && p->conv != '%')
    {
        if (p->conv == 'd' || p->conv == 'i')
            ch = '0';
        ft_add(ft_padstr(ch, p->precision - len), output);
    }
    ft_add(res, output);
    if (p->flag_minus)
        ft_add(ft_padstr(ch, p->min_width - len), output);
}

void		ft_add(char *str, t_output **output)
{
	t_output	*out;

	out = *output;
	out->len += ft_strlen(str);
	out->res = ft_strjoin(out->res, str);
}
