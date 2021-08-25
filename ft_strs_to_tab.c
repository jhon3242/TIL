//  main.c

#include "ft_point.h"
#include <stdlib.h>

int ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char * ft_strdup(char *src)
{
    int     i;

    i = 0;
    char * tmp = (char *)malloc(sizeof(char)*ft_strlen(src) + 1);
    if (tmp == NULL)
        return (0);
    while (src[i])
    {
        tmp[i] = src[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}


struct s_stock_str *    ft_strs_to_tab(int ac, char **av)
{
    int     i;
    t_stock_str *      tmp;

    i = 0;
    tmp = (t_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
    if (tmp == NULL)
        return (0);
    while (i<ac)
    {
        tmp[i].size = ft_strlen(av[i]);
        tmp[i].str = av[i];
        tmp[i].copy = ft_strdup(av[i]);
        i++;
    }

    tmp[i].size = 0;
    tmp[i].str = 0;
    tmp[i].copy = 0;
    return (tmp);
}