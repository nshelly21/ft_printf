#include "includes/ft_printf.h"

void 	negnb_handler(t_printf *printf_struct)
{
    int	i;

    i = 0;
    while (printf_struct->res[i] == ' ')
        i++;
    if (--i >= 0)
        printf_struct->res[i] = '-';
    else
    {
        if (printf_struct->res[0] == '0' && printf_struct->size > printf_struct->accuracy)
            printf_struct->res[0] = '-';
        else
            printf_struct->res = put_char_first(printf_struct->res, '-');
    }
}

void 	inf_case_handler(t_printf *ps)
{
    int	i;

    i = 0;
    while (ps->res[i] == ' ')
        i++;
    if (--i >= 0)
        ps->res[i] = ps->is_plus? '+' : ' ';
    else
        ps->res = put_char_first(ps->res, ps->is_plus? '+' : ' ');
}

int 	count_dig(int nb)
{
    int dig;

    dig = 1;
    while (nb /= 10)
        dig++;
    return(dig);
}

