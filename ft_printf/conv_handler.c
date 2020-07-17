/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:07:05 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/17 13:08:54 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_handler(va_list ap, t_printf *printf_struct)
{
	if (printf_struct->conv == 's')
		printf_struct->res = conv_string(ap, printf_struct);
	if (printf_struct->conv == 'c' || printf_struct->error_conv != -42)
		printf_struct->res = conv_char(ap, printf_struct);
	if (printf_struct->conv == 'p')
		conv_pointer(ap, printf_struct);
	if (printf_struct->conv == 'd' || printf_struct->conv == 'i')
		printf_struct->res = conv_int(ap, printf_struct);
	if (printf_struct->conv == 'o')
		printf_struct->res = conv_oct(ap, printf_struct);
	if (printf_struct->conv == 'u')
		printf_struct->res = conv_unsint(ap, printf_struct);
	if (printf_struct->conv == 'x')
		printf_struct->res = conv_hex(ap, printf_struct);
	if (printf_struct->conv == 'X')
		printf_struct->res = capitalize(conv_hex(ap, printf_struct));
	if (printf_struct->conv == 'f')
		conv_float(ap, printf_struct);
	if (printf_struct->conv == 'F')
		printf_struct->res = capitalize(conv_hex(ap, printf_struct));
	if (printf_struct->conv == '%')
		conv_percent(printf_struct);
	if (printf_struct->res)
		printf_struct->res_len = ft_strlen(printf_struct->res);
}
