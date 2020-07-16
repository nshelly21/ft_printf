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

    if (value == 0)
	{
    	printf_struct->zero_arg = 1;
    	if (!(printf_struct->accuracy) && printf_struct->is_point)
    		return (ft_strnew(0));
    	return (ft_strdup("0"));
	}
    if (value < 0)
    {
    	printf_struct->is_plus = 0;
        printf_struct->is_neg = 1;
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

	if (value == 0)
	{
		printf_struct->zero_arg = 1;
		if (!(printf_struct -> accuracy) && printf_struct->is_point &&
		!(printf_struct->conversion == 'o' && printf_struct->is_hash) &&
		!(printf_struct->conversion == 'f' || printf_struct->conversion == 'F'))
			return (ft_strnew(0));
		return (ft_strdup("0"));
	}
	if ((res = (char *)malloc(sizeof(char) * 65)) == NULL)
		return (ft_strdup("malloc error")); //TODO make proper exit function
	res = ft_itoa_printf_u2(value, base, res);
	return (res);
}