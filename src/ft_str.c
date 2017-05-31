//
// Created by akinfemi on 5/29/17.
//

#include <ft_printf.h>

char    *ft_padstr(char ch, int len)
{
    char    *res;
    int     i;

    res = (char *)ft_memalloc(sizeof(char)*(len + 1));
    i = -1;
    while(++i < len)
        res[i] = ch;
    return (res);
}