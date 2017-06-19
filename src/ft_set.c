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

#include <ft_printf.h>
//#include <stdio.h> /* Remove later !!!!!!!!!!!!!!!!*/

void		set_flags(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
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
		params->flag_minus = 1;
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
	if (ft_is_slmod(str))
	{
		params->lmod = ft_toupper(*str);
		str += 2;
	}
	if (ft_is_lmod(*str, &params))
		str++;
	*fmt = str;
}

void		set_min_width(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	if (*str >= '1' && *str <= '9') {
        params->min_width = ft_atoi(str);
        while (*str >= '0' && *str <= '9')
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
	if (*str == '.')
	{
		params->period = 1;
		str++;
		if (*str >= '0' && *str <= '9')
		{
			params->precision = ft_atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
		}
	}
	*fmt = str;
}

void		set_args(t_format **p, const char **fmt)
{
	t_format		*params;
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