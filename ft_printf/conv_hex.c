/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_usint_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:47:47 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/17 14:31:45 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*conv_hex25(va_list ap, t_printf *printf_struct, \
		t_unsint unsint_struct)
{
	if (printf_struct->is_hh)
	{
		unsint_struct.shortnb = (unsigned char)va_arg(ap, int);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct.\
					shortnb, 16, printf_struct));
	}:i
	return (NULL);
}

static char	*conv_hex_continue(va_list ap, t_printf *printf_struct,\
		t_unsint *unsint_struct)
{
	if (!(printf_struct->is_l || printf_struct->is_ll || \
				printf_struct->is_h || printf_struct->is_hh))
	{
		unsint_struct->intnb = (unsigned int)va_arg(ap, int);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct->\
					intnb, 16, printf_struct));
	}
	if (printf_struct->is_ll)
	{
		unsint_struct->longlongnb = (unsigned long long)va_arg(ap, long long);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct->\
					longlongnb, 16, printf_struct));
	}
	if (printf_struct->is_h)
	{
		unsint_struct->shortnb = (unsigned short)va_arg(ap, int);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct->\
					shortnb, 16, printf_struct));
	}
}

char		*conv_hex(va_list ap, t_printf *printf_struct)
{
	t_unsint	unsint_struct;

	init_t_unsint(&unsint_struct);
	if (printf_struct->is_l)
	{
		unsint_struct.longnb = (unsigned long)va_arg(ap, long);
		return (ft_itoa_printf_u1((unsigned long long)unsint_struct.longnb, \
		16, printf_struct));
	}
	conv_hex_continue(ap, printf_struct, &unsint_struct);
	return (conv_hex25(ap, printf_struct, unsint_struct));
}
