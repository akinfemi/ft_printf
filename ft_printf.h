/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:04:43 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/26 12:42:48 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	s_format
{
	int 		minus;
	int 		plus;
	int 		zero;
	int 		hash;
	int 		space;
	int			min_width;
	int			period;
	int			precision;
	char		conv;
	int			perc;
	char		lmod;
}				t_format;
void	ft_add(char *str, char **res);
void	ft_parse(va_list ap, const char **fmt, char **res);
void	ft_build(va_list ap, t_format *p, const char **fmt, char **res);
void	set_flags(t_format **p, const char **fmt);
void	set_min_width(t_format **p, const char **fmt);
void	set_precision(t_format **p, const char **fmt);
void	set_args(t_format **p, const char **fmt);
int		ft_is_conv(char *str);

/*
 * Temp function
 */
void	test_set(t_format *p);
#endif
