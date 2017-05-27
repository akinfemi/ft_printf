/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:01:37 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/27 00:42:04 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
/*	if (ft_strncmp(str, "hh", 2) == 0 || ft_strncmp(str, "ll", 2) == 0) //while? if both together are possible
	{
		params->flags = ft_strncat(params->flags, str, 2);
		str += 2;
	}*/
//	while (*str)
//	{
		if (*str == 'h' || *str == 'l' || *str == 'z' || *str == 'j' || *str == '#' || *str == '0' || *str == '-' || *str == '+' || *str == ' ')
			params->flags = ft_strncat(params->flags, str, 1);
//		else
//			break;
//		str++;
//	}
	*fmt = str;
}

void		set_min_width(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	params->min_width = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	*fmt = str;
}

void		set_period(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	if (*str == '.')
	{
		params->period = 1;
		str++;
	}
	*fmt = str;
}

void		set_precision(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	params->precision = ft_atoi(str);
	while (*str > '0' && *str < '9')
		str++;
	*fmt = str;
}

void		set_args(t_format **p, const char **fmt)
{
	t_format	*params;
	const char		*str;

	str = *fmt;
	params = *p;
	if (*str == 's' || *str == 'S' || *str == 'p' || *str == 'd' || *str == 'D' || *str == 'i' 
			|| *str == 'o' || *str == 'O' || *str == 'u' || *str == 'U' || *str == 'x' || *str == 'X' || *str == 'c' || *str == 'C')
		params->conv = *str++;
	*fmt = str;
}
