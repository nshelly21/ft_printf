#include "includes/ft_printf.h"


void 	accuracy_handler(t_printf *printf_struct)
{
    char 	*tmp;
    int 	i;
    int 	len;

    tmp = NULL;
    i = 0;
    len = 0;
    if (printf_struct->res)
        len = printf_struct->accuracy - (int)ft_strlen(printf_struct->res);
    if (!(tmp = (char*)malloc(sizeof(char) * len + 1)))
        return ;
    while (i < len && printf_struct->conversion != 's')
        tmp[i++] = '0';
    tmp[i] = '\0';
    printf_struct->res = ft_strjoin(tmp, printf_struct->res);
    free(tmp);
}

void 	size_handler(t_printf *printf_struct)
{
    char 	*tmp;
    int 	i;
    int 	len;

    tmp = printf_struct->res;
    i = 0;
    len = 0;
    if (printf_struct->conversion == 'c' && printf_struct->zero_arg)
        printf_struct->size -= 1;
    if (printf_struct->res)
        len = printf_struct->size - (int)ft_strlen(printf_struct->res);
    if (!(tmp = (char*)malloc(sizeof(char) * len + 1)))
        return ;
    while (i < len)
        tmp[i++] = ' ';
    tmp[i] = '\0';
    printf_struct->res = ft_strjoin(tmp, printf_struct->res);
    free(tmp);
}

void	accuracy_and_size_handler(t_printf *printf_struct)
{
    if (printf_struct->accuracy && (int)ft_strlen(printf_struct->res) < printf_struct->accuracy && (printf_struct->conversion != 'f' && printf_struct->conversion != 'F'))
        accuracy_handler(printf_struct);
    if (printf_struct->size && (int)ft_strlen(printf_struct->res) < printf_struct->size)
        size_handler(printf_struct);
}

