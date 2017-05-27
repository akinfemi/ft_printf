/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:15:35 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/27 00:28:19 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_params(t_format **p)
{
	t_format	*params;

	params = *p;
	params->min_width = 0;
	params->precision = 0;
	params->space = 0;
	params->zero = 0;
	params->hash = 0;
	params->plus = 0;
	params->period = '\0';
	params->conv = '\0';
}

void		ft_parse(va_list ap, const char **fmt, char **res)
{
	t_format	*params;

	params  = (t_format *)malloc(sizeof(t_format *));
	init_params(&params);
	*fmt = *fmt + 1;
	set_flags(&params, fmt);
	set_min_width(&params, fmt);
	set_period(&params, fmt);
	set_precision(&params, fmt);
	set_args(&params, fmt);
	ft_build(ap, params, fmt, res);/*build resulting string based on the combination of the flags*/
}
