/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 09:22:25 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/27 00:27:55 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

char		*ft_pad(char ch, int len)
{
	char	*ans;

	ans = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (--len >= 0)
		ans[len] = ch;
	return (ans);
}

void		ft_build(va_list ap, t_format *params, const char **fmt, char **res)
{
	if (params->min_width > 0 && params->zero)
		ft_add(ft_pad('0', params->min_width), res);
	else if (params->min_width > 0)
		ft_add(ft_pad(' ', params->min_width), res);
	if (params->conv == 'd')
		ft_add(ft_itoa(va_arg(ap, int)), res);
}
void		ft_add(char *str, char **res)
{
	*res = ft_strjoin(*res, str);
}
