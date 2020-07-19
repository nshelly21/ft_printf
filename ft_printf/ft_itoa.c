/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:23:36 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/19 02:04:42 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_itoa_printf2(long long num, int base, t_printf *printf_struct)
{
	int					i;
	int					ostatok;
	char				*res;
	char 				*tmp;

	i = 0;
	ostatok = 0;
	if ((res = (char *)malloc(sizeof(char) * 65)) == NULL)
		return (exit_error("malloc unsuccessful", printf_struct));
	while (num != 0)
	{
		ostatok = num % base;
		res[i++] = (ostatok > 9) ? (ostatok - 10) + 'a' : ostatok + '0';
		num /= base;
	}
	res[i] = '\0';
	tmp = res;
	free(tmp);
	return (ft_strrev(res));
}

char		*ft_itoa_printf1(long long value, int base, t_printf *printf_struct)
{
	int num;
	
	num = value;
	if (num == 0)
	{
		printf_struct->zero_arg = 1;
		if (!(printf_struct->accuracy) && printf_struct->is_point)
			return (ft_strnew(0));
		return (ft_strdup("0"));
	}
	if (num < 0)
	{
		printf_struct->is_plus = 0;
		printf_struct->is_neg = 1;
		num = num * (-1);
	}
	return (ft_itoa_printf2(num, base, printf_struct));
}

static char	*ft_itoa_printf_u2(unsigned long long value, int base, t_printf *ps)
{
	int					i;
	unsigned long long	ostatok;
	char				*res;
	char				*tmp;

	i = 0;
	ostatok = 0;
	if (!(res = (char *)malloc(sizeof(char) * 65)))
		exit_error("malloc unsuccessful", ps);
	while (value != 0)
	{
		ostatok = value % base;
		res[i++] = (ostatok > 9) ? ostatok - 10 + 'a' : ostatok + '0';
		value /= base;
	}
	res[i] = '\0';
	tmp = res;
	free(tmp);
	return (ft_strrev(res));
}

char		*ft_itoa_printf_u1(unsigned long long value, int base, t_printf *ps)
{
	if (value == 0)
	{
		ps->zero_arg = 1;
		if (!(ps->accuracy) && ps->is_point &&
			!(ps->conv == 'o' && ps->is_hash) &&
			!(ps->conv == 'f' || ps->conv == 'F'))
			return (ft_strnew(0));
		return (ft_strdup("0"));
	}
	return(ft_itoa_printf_u2(value, base, ps));
}

int			where_start(char *res, t_printf *printf_struct)
{
	int i;

	i = 0;
	while ((res[i] == ' ' || res[i] == '0') &&
		i < (int)ft_strlen(res) - printf_struct->res_len)
		i++;
	return (i);
}
