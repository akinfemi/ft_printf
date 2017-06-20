/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:08:23 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/19 23:09:51 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_is_dioux(char c)
{
	char	*conv;

	conv = "DdioOuxX";
	while (*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}

int		ft_is_diox(char c)
{
	char	*conv;

	conv = "DdioOxX";
	while (*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}

int		ft_is_di(char c)
{
	char	*conv;

	conv = "Ddi";
	while (*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}
