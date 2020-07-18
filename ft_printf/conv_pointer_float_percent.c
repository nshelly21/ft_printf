/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer_float_percent.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:44:03 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/17 14:36:49 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_pointer(va_list ap, t_printf *printf_struct)
{
	void		*str;
	long long	k;

	str = va_arg(ap, void*);
	k = (long long)str;
	printf_struct->res = ft_itoa_printf1(k, 16, printf_struct);
}

void	conv_percent(t_printf *printf_struct)
{
	if (!(printf_struct->res = malloc(sizeof(char) * 2)))
		return (exit_error(printf_struct));
	printf_struct->res[0] = '%';
	printf_struct->res[1] = '\0';
}

void	conv_float(va_list ap, t_printf *ps)
{
	long double	nb;

	nb = (long double)va_arg(ap, double);
	if (!(ps->accuracy) && !(ps->is_point))
		ps->accuracy = 6;
	if ((1.0 / 0.0) == nb)
	{
		ps->is_inf = 1;
		ps->res = (ps->conv == 'f' ? "inf" : "INF");
		return ;
	}
	if (nb < 0)
	{
		ps->is_neg = 1;
		nb = nb * (-1);
	}
	float_handler(nb, ps);
}
