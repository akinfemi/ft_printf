/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:17:57 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/17 21:47:04 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
static int		get_len(uintmax_t nbr, int base)
{
	int i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr/=base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(uintmax_t val, int base)
{
	int8_t len;
	char *str;
	int sign = 1;

	len = get_len(val, base) + (sign < 0);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (val == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (val != 0)
	{
		str[--len] = (val % base) + (val % base > 9 ? 'a' - 10 : '0');
		val/=base;
	}
	return (str);
}
