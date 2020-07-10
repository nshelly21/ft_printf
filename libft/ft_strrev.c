//
// Created by Denisse Gruyere on 7/10/20.
//

#include "libft.h"

char    *ft_strrev(char *str)
{
    int     len;
    char    buf;
    int     i;

    i = 0;
    len = ft_strlen(str);
    while (len - 1 > i)
    {
        buf = str[len];
        str[len - 1] = str[i];
        str[i] = buf;
        len--;
        i++;
    }
    return(str);
}