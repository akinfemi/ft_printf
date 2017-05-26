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

#include "ft_printf.h"
#include <stdio.h>
int			ft_print(const char *fmt, va_list ap)
{
	const char	*temp;
	char	*res;

	temp = "\0";
	while (fmt && *fmt)
	{
		temp = ft_strchr(fmt, '%');
		if (!temp || (temp && ft_strlen(fmt) - ft_strlen(temp) > 0))
			ft_add(ft_strndup(fmt, ft_strlen(fmt) - ft_strlen(temp)), &res);
		fmt = temp;
		if (fmt)
			ft_parse(ap, &fmt, &res);
	}
	ft_putstr(res);
	return (ft_strlen(res));
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
