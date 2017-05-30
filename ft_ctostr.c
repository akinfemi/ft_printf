//
// Created by Akinfemi Akin-Aluko on 5/30/17.
//

#include "ft_printf.h"
char        *ft_ctostr(char ch)
{
    char    *c;

    c = (char *)ft_memalloc(sizeof(char)*2);
    c[0] = ch;
    c[1] = '\0';
    return (c);
}