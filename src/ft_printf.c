/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:02:34 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/26 11:01:24 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
//#include <stdio.h>
//#include <stdlib.h>
void        ft_repnull(t_output **output)
{
    t_output    *out;
    char        *str;

    out = *output;
    str = out->res;
    while (*str)
    {
        if (*str == 127)
            *str = 0;
        str++;
    }
}
int			ft_print(const char *fmt, va_list ap)
{
	const char	*temp;
	t_output	*output;
    int         out_len;

    out_len = 0;
	output = (t_output *)malloc(sizeof(t_output));
    init_output(&output);
	while (fmt && *fmt)
	{
		clean_output(&output);
		temp = ft_strchr(fmt, '%');
		if (!temp || temp - fmt > 0)
			ft_add(ft_strndup(fmt, temp - fmt), &output, 0);
		fmt = temp;
		if (fmt)
			ft_parse(ap, &fmt, &output);
        out_len += ft_strlen(output->res);
        ft_repnull(&output);
		write(1, output->res, ft_strlen(output->res));
	}
	return (out_len);
}

int			ft_printf(const char *fmt, ...)
{
	int		res;

	va_list	ap;
	va_start (ap, fmt);
	res = ft_print(fmt, ap);
	va_end(ap);
	return (res);
}
