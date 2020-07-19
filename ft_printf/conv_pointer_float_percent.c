/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer_float_percent.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:44:03 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/19 00:23:14 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*conv_pointer(va_list ap, t_printf *printf_struct)
{
	void		*str;
	char 		*res;
	long long	k;

	str = va_arg(ap, void*);
	k = (long long)str;
	res = ft_itoa_printf1(k, 16, printf_struct);
	return (res);
}

char	*conv_percent(t_printf *printf_struct)
{
	char		*res;

	if (!(res = malloc(sizeof(char) * 2)))
		return (exit_error("malloc unsuccessful", printf_struct));
	res[0] = '%';
	res[1] = '\0';
	return (res);
}

int 	is_minus_zero(long double zero, t_printf *ps)
{
	if (1 / zero < 0)
	{
		ps->min_zero = 1;
		return (1);
	}
	else
		return (0);
}

char	*conv_float(va_list ap, t_printf *ps)
{
	long double	nb;
	char 		*res;

	res = NULL;
	nb = (long double)va_arg(ap, double);
	if (!(ps->accuracy) && !(ps->is_point))
		ps->accuracy = 6;
	if ((1.0 / 0.0) == nb)
	{
		ps->is_inf = 1;
		return (ft_strdup(ps->conv == 'f' ? "inf" : "INF"));
	}
	if (nb == 0 ? is_minus_zero(nb, ps): nb < 0)
	{
		ps->is_neg = 1;
		nb = nb * (-1);
	}
	res = float_handler(nb, ps, res);
	return (res);
}
