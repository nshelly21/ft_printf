//
// Created by Denisse Gruyere on 7/10/20.
//
#include "includes/ft_printf.h"

char	*ft_itoa_printf2(long long value, int base, char *str)
{
    int					i;
    int					ostatok;

    i = 0;
	ostatok = 0;
    while (value != 0)
    {
		ostatok = value % base;
        str[i++] = (ostatok > 9) ? (ostatok - 10) + 'a' : ostatok + '0';
		value /= base;
    }
    str[i] = '\0';
    return (ft_strrev(str));
}

char	*ft_itoa_printf1(long long value, int base, t_printf *printf_struct)
{
    char				*res;

    //TODO handle if num == 0;
    if (value < 0)
    {
        printf_struct->isneg = 1;
		value = value * (-1);
    }
    if ((res = (char *)malloc(sizeof(char) * 65)) == NULL)
        return (ft_strdup("malloc error")); //TODO make proper exit function
    res = ft_itoa_printf2(value, base, res);
    return (res);
}

char	*ft_itoa_printf_u2(unsigned long long value, int base, char *str)
{
	int					i;
	unsigned long long 	ostatok;

	i = 0;
	ostatok = 0;
	while (value != 0)
	{
		ostatok = value % base;
		str[i++] = (ostatok > 9) ? ostatok - 10 + 'a' : ostatok + '0';
		value /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*ft_itoa_printf_u1(unsigned long long value, int base, t_printf *printf_struct)
{
	char				*res;

	//TODO handle if num == 0;
	if ((res = (char *)malloc(sizeof(char) * 65)) == NULL)
		return (ft_strdup("malloc error")); //TODO make proper exit function
	res = ft_itoa_printf_u2(value, base, res);
	return (res);
}
