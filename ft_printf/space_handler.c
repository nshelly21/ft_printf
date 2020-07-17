#include "includes/ft_printf.h"

void 	space_handler25(t_printf *printf_struct)
{
    int	i;

    if (printf_struct->is_zero)
    {
        if (printf_struct->res_len < printf_struct->size)
            printf_struct->res[0] = ' ';
        else if (printf_struct->res_len >= printf_struct->size)
            printf_struct->res = put_char_first(printf_struct->res, ' ');
    }
    else
    {
        i = where_start(printf_struct);
        if (i > 0)
            printf_struct->res[--i] = ' ';
        else if (i == 0)
            printf_struct->res = put_char_first(printf_struct->res, ' ');
    }
}

void 	space_handler(t_printf *printf_struct)
{
    if (printf_struct->accuracy && printf_struct->size)
    {
        if (printf_struct->accuracy > printf_struct->size)
        {
            if (printf_struct->res_len < printf_struct->accuracy)
                printf_struct->res[printf_struct->size - printf_struct->accuracy - 1] = ' ';
            else if ((printf_struct->conversion == 'f' || printf_struct->conversion == 'F') &&
                     printf_struct->size > printf_struct->res_len)
                printf_struct->res[printf_struct->size - printf_struct->res_len -
                                   printf_struct->is_point] = ' ';
            else if (printf_struct->res_len >= printf_struct->accuracy)
                printf_struct->res = put_char_first(printf_struct->res, ' ');
        }
        else if (printf_struct->size <= printf_struct->accuracy)
            printf_struct->res = put_char_first(printf_struct->res, ' ');
    }
    else if (printf_struct->size)
        space_handler25(printf_struct);
    else if (printf_struct->accuracy)
        printf_struct->res = put_char_first(printf_struct->res, ' ');
    else if (!printf_struct->accuracy || !printf_struct->size)
        printf_struct->res = put_char_first(printf_struct->res, ' ');
}
