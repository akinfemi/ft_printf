//
// Created by akinfemi on 5/29/17.
//

#include "ft_printf.h"
char    *ft_padstr(char ch, size_t len)
{
    char    *res;
    size_t  i;

    res = (char *)ft_memalloc(sizeof(char)*(len + 1));
    i = -1;
    while(++i < len)
        res[i] = ch;
    return (res);
}

char        *ft_ctostr(char ch)
{
    char    *c;

    c = (char *)ft_memalloc(sizeof(char)*2);
    c[0] = ch;
    c[1] = '\0';
    return (c);
}