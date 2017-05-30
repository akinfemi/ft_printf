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
typedef struct	s_output
{
	char 		*res;
	size_t 		len;
}				t_output;
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
void	    ft_add(char *str, t_output **output);
void	    ft_parse(va_list ap, const char **fmt, t_output **output);
void    	ft_build(va_list ap, t_format *p, t_output **output);
void    	set_flags(t_format **p, const char **fmt);
void	    set_min_width(t_format **p, const char **fmt);
void	    set_precision(t_format **p, const char **fmt);
void	    set_args(t_format **p, const char **fmt);
int		    ft_is_conv(char *str);
void	    init_output(t_output **output);
char        *handle_conv(va_list ap, char arg);
char    	*ft_padstr(char ch, size_t len);
/*
 * Temporary function
 */
void	test_set(t_format *p);
#endif
