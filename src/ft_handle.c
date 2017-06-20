/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:50:41 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/19 23:05:34 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	handle_padding(t_format **params, t_output **out, char *res, int len)
{
	t_format	*p;
	char		ch;
	int			sg;
	int			n;

	p = *params;
	sg = (p->plus || p->minus) ? 1 : 0;
	len = set_len(params, res, len);
	ch = set_ch(params);
	add_prefix(params, out, res, ch);
	if (p->min_width > p->precision && p->flag_minus == 0 && p->conv != '%')
	{
		n = p->min_width - (p->hash && ft_tolower(p->conv) == 'o');
		ft_add(ft_padstr(ch, n - sg - len - p->space), out, 3);
	}
	else if (p->min_width > 0 && p->flag_minus == 0 && p->conv == '%')
	{
		n = p->min_width - ft_strlen(res);
		ft_add(ft_padstr(ch, n), out, 3);
	}
	else if (p->precision > p->min_width && p->min_width > len)
		ft_add(ft_padstr(ch, p->min_width - len), out, 3);
	add_postfix(params, out, res, ch);
}

void	add_postfix(t_format **params, t_output **output, char *res, char ch)
{
	t_format	*p;

	p = *params;
	if (p->hash && ft_isox(p->conv) && p->zero == 0 && *res != '0')
		handle_hash(&p, output);
	if (p->minus && ch == ' ')
		handle_minus(params, output);
	if (ch == ' ' && p->plus)
		handle_plus(params, output);
}

void	handle_precision(t_format **params, t_output **output, int len)
{
	t_format	*p;
	char		*tmp;

	p = *params;
	tmp = ft_padstr('0', p->precision - len);
	if (ft_is_dioux(p->conv) && p->precision > len)
		ft_add(tmp, output, 3);
}

void	handle_res(t_format **params, t_output **output, char *res, int len)
{
	t_format	*p;

	p = *params;
	if (!res && p->conv == 's')
		res = "(null)";
	else if (p->conv == 's' && p->precision != 0 && p->precision < len)
		res = ft_strndup(res, p->precision);
	else if (res && *res == '0' && ft_is_dioux(p->conv) && p->period == 1)
	{
		*res = '\0';
		if (p->hash && (p->conv == 'o' || p->conv == 'O'))
			*res = '0';
		if (p->min_width > 0)
			*res = ' ';
		if (ft_is_dioux(p->conv) && p->precision > 1)
			*res = '0';
	}
	ft_add(res, output, 1);
	if (ft_strlen(res) == 0 && p->conv == 'c')
		ft_add(res, output, 2);
}

void	handle_alignment(t_format **params, t_output **output)
{
	t_format	*p;
	t_output	*out;

	p = *params;
	out = *output;
	if (p->flag_minus && p->min_width > out->len)
		ft_add(ft_padstr(' ', p->min_width - out->len), output, 3);
}
