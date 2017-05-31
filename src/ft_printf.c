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

int			ft_print(const char *fmt, va_list ap)
{
	const char	*temp;
	t_output	*output;
    int         out_len;

    out_len = 0;
	output = (t_output *)malloc(sizeof(t_output));
	while (fmt && *fmt)
	{
		init_output(&output);
		temp = ft_strchr(fmt, '%');
		if (!temp || (ft_strlen(fmt) - ft_strlen(temp) > 0))
			ft_add(ft_strndup(fmt, ft_strlen(fmt) - ft_strlen(temp)), &output, 0);
		fmt = temp;
		if (fmt)
			ft_parse(ap, &fmt, &output);
		ft_putstr(output->res);
        out_len += ft_strlen(output->res);
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
