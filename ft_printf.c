/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:02:34 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/12 14:08:40 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_print(const char *fmt, va_list ap)
{
	const char	*temp;
	char	*str;

	while (*fmt)
	{
		temp = ft_strchr(fmt, '%');
		if (temp && ft_strlen(temp) > 0)
		{
			str = ft_strndup(fmt, temp-fmt);
			ft_putendl(str);
		}
		fmt = temp + 1;
	}
//	ft_putstr(str);
	str = va_arg(ap, char*);
	return (ft_strlen(str));
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
