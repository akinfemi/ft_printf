//
// Created by Akinfemi Akin-Aluko on 5/30/17.
//
#include "ft_printf.h"
#include <stdio.h>
int			ft_printf(const char *fmt,...);

int main()
{
    ft_printf("Mine: %5d %c %.5%\n",-10,'s');
    printf("Real: %5d %c %.5%\n",-10,'s');
    printf("<------------------------>\n");
    ft_printf("Mine: %-10.5 d %c %.5%\n",10000,'s');
    printf("Real: %-10.5 d %c %.5%\n",10000,'s');
    return (0);
}