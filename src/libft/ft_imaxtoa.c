/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:17:11 by exam              #+#    #+#             */
/*   Updated: 2017/03/08 23:47:31 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(intmax_t value)
{
    uintmax_t	i;
    intmax_t	size;
    char		*ret;

    i = (value < 0) ? -value : value;
    size = 1 + (value < 0);
    while ((i /= 10))
        size++;
    ret = (char *)malloc(sizeof(char) * (size + 1));
    ret[size] = '\0';
    i = (value < 0) ? -value : value;
    ret[--size] = "0123456789"[i % 10];
    while ((i /= 10))
        ret[--size] = "0123456789"[i % 10];
    if (value < 0)
        ret[--size] = '-';
    return (ret);
}
