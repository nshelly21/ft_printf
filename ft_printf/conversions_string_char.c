#include "includes/ft_printf.h"

char    *conv_string(va_list ap, t_printf *printf_struct)
{
    char	*identified_string;
    char	*res;
    int 	i;

    i = -1;
    identified_string = va_arg(ap, typeof(identified_string));
    if (!identified_string && !printf_struct->is_point)
        return (ft_strdup("(null)"));
    if (!printf_struct->accuracy && printf_struct->is_point)
        return (ft_strnew(0));
    if (!printf_struct->accuracy)
    {
        if (!(res = (char *) malloc(sizeof(char) * (ft_strlen(identified_string) + 1))))
            return (0); //TODO write proper exit_error function
        res = ft_strcpy(res, identified_string);
    }
    else
    {
        if (!(res = (char *) malloc(sizeof(char) * (printf_struct->accuracy + 1))))
            return (0);
        while (++i < printf_struct->accuracy)
            res[i] = identified_string[i];
        res[i] = '\0';
    }
    return (res);
}

char    *conv_char(va_list ap, t_printf *printf_struct)
{
    char identified_char;
    char *res;

    if (printf_struct->error_conv == -42)
        identified_char = va_arg(ap, int);
    else
    identified_char = printf_struct->error_conv;
    if (identified_char == 0)
    {
        printf_struct->zero_arg = 1;
        if (printf_struct->error_conv == -42)
            printf_struct->ret_value += 1;
        return (ft_strnew(0));
    }
    if (!(res = (char*)malloc(sizeof(char) * 2)))
        return (0); //TODO write proper exit_error function
    res[0] = identified_char;
    res[1] = '\0';
    return (res);
}