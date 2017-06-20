/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:01:37 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/19 23:23:43 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		set_flags(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	params->hash = (*str == '#') ? 1 : params->hash;
	params->zero = (*str == '0') ? 1 : params->zero;
	params->flag_minus = (*str == '-') ? 1 : params->flag_minus;
	params->plus = (*str == '+') ? 1 : params->plus;
	params->space = (*str == ' ') ? 1 : params->space;
	if (ft_is_flag(*str))
		str++;
	if (ft_is_slmod(str))
	{
		params->lmod = ft_toupper(*str);
		str += 2;
	}
	if (ft_is_lmod(*str, &params))
		str++;
	*fmt = str;
}

int			ft_is_flag(char arg)
{
	char	*str;

	str = "#0+- ";
	while (*str)
	{
		if (*str == arg)
			return (1);
		str++;
	}
	return (0);
}

void		set_min_width(t_format **p, const char **fmt)
{
	t_format	*params;
	const char	*str;

	str = *fmt;
	params = *p;
	if (*str >= '1' && *str <= '9')
	{
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
		params->precision = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	*fmt = str;
}

void		set_args(t_format **p, const char **fmt)
{
	t_format		*params;
	const char		*str;

	str = *fmt;
	params = *p;
	if (ft_is_conv((char *)str))
	{
		params->conv = *str;
		str++;
	}
	*fmt = str;
}
