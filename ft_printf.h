/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:04:43 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/26 12:04:39 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

typedef struct s_format
{
	char		*flags;
	int			min_width;
	char		period;
	int			max_width;
	char		conv;
	int			perc;
}				t_format;
void	ft_add(char *str, char **res);
void	ft_parse(va_list ap, const char **fmt, char **res);
void	ft_build();
void	set_flags(t_format **p, const char **fmt);
void	set_min_width(t_format **p, const char **fmt);
void	set_period(t_format **p, const char **fmt);
void	set_max_width(t_format **p, const char **fmt);
void	set_args(t_format **p, const char **fmt);

#endif
