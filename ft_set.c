/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:01:37 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/26 12:47:56 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		set_flags(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	if (*str == '%')
	{
		params->perc = 1;
		str++;
	}
	if (*str == '#')
	{
		params->hash = 1;
		str++;
	}
	if (*str == '0')
	{
		params->zero = 1;
		str++;
	}
	if (*str == '-')
	{
		params->minus = 1;
		str++;
	}
	if (*str == '+')
	{
		params->plus = 1;
		str++;
	}
	if (*str == ' ')
	{
		params->space = 1;
		str++;
	}
	if (*str == 'h' || *str == 'l' || *str == 'z' || *str == 'j') //needs to be reworked for priority of flags
	{
		params->lmod = *str;
		str++;
	}
	*fmt = str;
}

void		set_min_width(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	if (*str >= '0' && *str <= '9')
		params->min_width = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	*fmt = str;
}

void		set_precision(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	if (*str == '.')
	{
		params->period = 1;
		str++;
		params->precision = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	*fmt = str;
}

void		set_args(t_format **p, const char **fmt)
{
	t_format	*params;
	const char		*str;

	str = *fmt;
	params = *p;
	if(ft_is_conv((char *)str))
	{
		params->conv = *str;
		str++;
	}
	*fmt = str;
}
/*
 * Temporary Function
 */
void		test_set(t_format *params)
{
	if (params->conv)
		printf("Conversion: %c\n",params->conv);
	if (params->precision || params->period)
		printf("Precision: %d, Period: %d\n",params->precision, params->period);
	if (params->min_width)
		printf("Min_Width: %d\n", params->min_width);
	if (params->lmod)
		printf("lmod: %c\n", params->lmod);
	if (params->space)
		printf("space: %d\n", params->space);
	if (params->zero)
		printf("Zero: %d\n", params->zero);
	if (params->hash)
		printf("Hash: %d\n", params->hash);
	if (params->plus)
		printf("Plus: %d\n", params->plus);
	if (params->minus)
		printf("Minus: %d\n", params->minus);
	if (params->perc)
		printf("Percentage: %c\n", params->perc);
}