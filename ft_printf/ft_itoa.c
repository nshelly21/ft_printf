/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:23:36 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 20:53:53 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_itoa_printf2(long long value, int base, char *str)
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

char		*ft_itoa_printf1(long long value, int base, t_printf *printf_struct)
{
	char				*res;
	char				*tmp;

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
	{
		exit_error(printf_struct);
		return (ft_strdup("malloc error"));
	}
	tmp = res;
	res = ft_itoa_printf2(value, base, res);
	free(tmp);
	return (res);
}

static char	*ft_itoa_printf_u2(unsigned long long value, int base, char *str)
{
	int					i;
	unsigned long long	ostatok;

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

char		*ft_itoa_printf_u1(unsigned long long value, int base, t_printf *ps)
{
	char				*res;
	char				*tmp;

	if (value == 0)
	{
		ps->zero_arg = 1;
		if (!(ps->accuracy) && ps->is_point &&
			!(ps->conv == 'o' && ps->is_hash) &&
			!(ps->conv == 'f' || ps->conv == 'F'))
			return (ft_strnew(0));
		return (ft_strdup("0"));
	}
	if ((res = (char *)malloc(sizeof(char) * 65)) == NULL)
	{
		exit_error(ps);
		return (ft_strdup("malloc error"));
	}
	tmp = res;
	res = ft_itoa_printf_u2(value, base, res);
	free(tmp);
	return (res);
}

int			where_start(t_printf *printf_struct)
{
	int i;

	i = 0;
	while ((printf_struct->res[i] == ' ' || printf_struct->res[i] == '0') &&
		i < (int)ft_strlen(printf_struct->res) - printf_struct->res_len)
		i++;
	return (i);
}
