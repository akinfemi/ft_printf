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
    handle_space(&p, output);
    handle_padding(&p, output, res, len);
    handle_precision(&p, output, len);
    handle_res(&p, output, res, len);
    handle_alignment(&p, output);
}

void		ft_add(char *str, t_output **output, int signal)
{
    t_output *out;

    out = *output;
    if (signal == 1)
        out->len += ft_strlen(str);
    else if (signal == 2) {
        *str = 127;
        out->len += 1;
    }
    out->res = ft_strjoin(out->res, str);
}