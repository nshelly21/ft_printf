#include "includes/ft_printf.h"


void 	hash_float_handler(char *str, t_printf *printf_struct)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '.')
        i++;
    if (str[i] != '.')
        str[i] = '.';
    printf_struct->res = str;
}

void	float_handler(long double nb, t_printf *printf_struct)
{
    int		i;
    char	*dot;
    char 	*tmp;

    i = 0;
    printf_struct->res = ft_itoa_printf_u1((unsigned long long)nb, 10, printf_struct);
    dot = ft_strnew(0);
    while (++i <= printf_struct->accuracy + 1)
    {
        nb = nb - (unsigned long long)nb;
        nb = nb * 10;
        tmp = ft_itoa_printf_u1((unsigned long long)nb, 10, printf_struct);
        dot = ft_strjoin(dot, tmp);
    }
    dot = put_char_first(dot, '.');
    printf_struct->res = ft_strjoin(printf_struct->res, dot);
    round1(printf_struct);
}

void 	hash_oct_handler(char *str, t_printf *printf_struct)
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (--i >= 0)
        str[i] = '0';
    else
        printf_struct->res = put_char_first(printf_struct->res, '0');
}

void	hash_hex_handler25(char *hex, int j, t_printf *printf_struct)
{
    if  (printf_struct->res[0] == '0' && printf_struct->res[1] == '0' && j == 1)
        printf_struct->res[1] = hex[1];
    else if (printf_struct->res[0] == '0' && printf_struct->res[1] != '0' && j == 1)
    {
        printf_struct->res[0] = hex[1];
        printf_struct->res = put_char_first(printf_struct->res, hex[0]);
    }
    else if (printf_struct->res[0] != '0' && printf_struct->res[1] != hex[1])
        printf_struct->res = put_char_first(printf_struct->res, hex[j]);
}

void 	hash_hex_handler(t_printf *printf_struct)
{
    int		i;
    int 	j;
    char 	*hex;

    i = 0;
    j = 2;
    hex = printf_struct->conversion == 'X' ? "0X" : "0x";
    while (printf_struct->res[i] == ' ')
        i++;
    while (--j >= 0)
    {
        if (--i >= 0)
        {
            if (printf_struct->conversion == 'x' || printf_struct->conversion == 'X'
                || printf_struct->conversion == 'p')
                printf_struct->res[i] = hex[j];
        }
        else
        {
            if (printf_struct->size > printf_struct->accuracy)
                hash_hex_handler25(hex, j, printf_struct);
            else if (printf_struct->size <= printf_struct->accuracy)
            {
                printf_struct->res = put_char_first(printf_struct->res, hex[1]);
                printf_struct->res = put_char_first(printf_struct->res, hex[0]);
                break ;
            }
        }
    }
}

