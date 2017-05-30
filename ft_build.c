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
void	ft_build(va_list ap, t_format *p, t_output **output)
{
	char 		*res;
    t_output    *out;

    out = *output;
	res = handle_conv(ap, p->conv);
    out->len = ft_strlen(res);
    if (p->precision)
        ft_add(ft_padstr('0', p->precision - out->len), output);
    //others
    ft_add(res, output);
}
void		ft_add(char *str, t_output **output)
{
	t_output	*out;

	out = *output;
	out->len += ft_strlen(str);
	out->res = ft_strjoin(out->res, str);
}
