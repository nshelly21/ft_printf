/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:09:33 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/17 13:43:41 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*conv_oct25(va_list ap, t_printf *printf_struct, t_unsint unsint_struct)
{
	if (printf_struct->is_hh)
	{
		unsint_struct.shortnb = (unsigned char)va_arg(ap, int);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct.shortnb,\
					8, printf_struct));
	}
	return (NULL);
}

char	*conv_oct_continue(va_list ap, t_printf *printf_struct,\
		t_unsint *unsint_struct)
{
	if (printf_struct->is_l)
	{
		unsint_struct->longnb = (unsigned long)va_arg(ap, long);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct->longnb, 8,\
					printf_struct));
	}
	if (printf_struct->is_ll)
	{
		unsint_struct->longlongnb = (unsigned long long)va_arg(ap, long long);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct->longlongnb,\
					8, printf_struct));
	}
	if (printf_struct->is_h)
	{
		unsint_struct->shortnb = (unsigned short)va_arg(ap, int);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct->shortnb, \
					8, printf_struct));
	}
}

char	*conv_oct(va_list ap, t_printf *printf_struct)
{
	t_unsint	unsint_struct;

	init_t_unsint(&unsint_struct);
	if (!(printf_struct->is_l || printf_struct->is_ll || printf_struct->is_h \
				|| printf_struct->is_hh))
	{
		unsint_struct.intnb = (unsigned int)va_arg(ap, int);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct.intnb, 8, \
					printf_struct));
	}
	conv_oct_continue(ap, printf_struct, &unsint_struct);
	return (conv_oct25(ap, printf_struct, unsint_struct));
}

char	*conv_int25(va_list ap, t_printf *printf_struct)
{
	char	*res;
	t_int	int_struct;

	init_t_int(&int_struct);
	res = NULL;
	if (!(printf_struct->is_l && printf_struct->is_ll && printf_struct->is_h\
				&& printf_struct->is_hh))
	{
		int_struct.intnb = va_arg(ap, int);
		return (ft_itoa_printf1((long long)int_struct.intnb, 10, \
		printf_struct));
	}
	if (printf_struct->is_h == 1)
	{
		int_struct.shortnb = (short)va_arg(ap, int);
		return (ft_itoa_printf1((long long)int_struct.shortnb, 10, \
		printf_struct));
	}
	if (printf_struct->is_hh == 1)
	{
		int_struct.shortnb = (char)va_arg(ap, int);
		return (ft_itoa_printf1((long long)int_struct.shortnb, 10, \
		printf_struct));
	}
	return (res);
}

char	*conv_int(va_list ap, t_printf *printf_struct)
{
	t_int	int_struct;

	init_t_int(&int_struct);
	if (printf_struct->is_l == 1 || printf_struct->is_ll == 1)
	{
		int_struct.longlongnb = va_arg(ap, long long);
		if (int_struct.longlongnb < 0)
		{
			printf_struct->is_plus = 0;
			printf_struct->is_neg = 1;
		}
		if (int_struct.longlongnb < -9223372036854775807 || int_struct.\
		longlongnb > 9223372036854775807)
			return (ft_itoa_printf_u1((unsigned long long)int_struct.\
			longlongnb, 10, printf_struct));
		else
			return (ft_itoa_printf1(int_struct.longlongnb, 10, printf_struct));
	}
	return (conv_int25(ap, printf_struct));
}
