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
#include <libft.h>
#include <stdint.h>

typedef struct	s_output
{
	char 		*res;
	int 		len;
}				t_output;
typedef struct	s_format
{
	int 		minus;
	int 		plus;
	int 		zero;
	int 		hash;
	int 		space;
	int 		min_width;
	int			period;
	int	    	precision;
	char		conv;
	int			perc;
	char		lmod;
	int			flag_minus;
}				t_format;
void	    ft_add(char *str, t_output **output, int b);
void	    ft_parse(va_list ap, const char **fmt, t_output **output);
void    	ft_build(va_list ap, t_format *p, t_output **output);
void    	set_flags(t_format **p, const char **fmt);
void	    set_min_width(t_format **p, const char **fmt);
void	    set_precision(t_format **p, const char **fmt);
void	    set_args(t_format **p, const char **fmt);
int		    ft_is_conv(char *str);
void	    init_output(t_output **output);
char        *handle_conv(va_list ap, char arg, t_format *params);
char    	*ft_padstr(char ch, int len);
int			ft_is_slmod(const char *str);
int			ft_is_lmod(const char ch, t_format **params);
intmax_t    ft_di_len(va_list ap, t_format *params);
char        *ft_ctostr(char ch);
uintmax_t   ft_oux_len(va_list ap, t_format *params);
int		    ft_is_dioux(char c);
int		    ft_is_diox(char c);
int		    ft_is_di(char c);
uintmax_t   ft_U_len(va_list ap);
void        handle_hash(t_format **p, t_output **output);
void        handle_plus(t_format **params, t_output **output);
void        handle_space(t_format **params, t_output **output);
void        handle_padding(t_format **params, t_output **output, char *res, int len);
void        handle_minus(t_format **params, t_output **output);
void        handle_precision(t_format **params, t_output **output, int len);
void        handle_res(t_format **params, t_output **output, char *res, int len);
void        handle_alignment(t_format **params, t_output **output, int len);
/*
 * Temporary function
 */
void	test_set(t_format *p);
#endif
