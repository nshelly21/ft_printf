/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:07:05 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/18 23:33:12 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*conv_handler(va_list ap, t_printf *printf_struct)
{
	if (printf_struct->conv == 's')
		return (conv_string(ap, printf_struct));
	if (printf_struct->conv == 'c' || printf_struct->error_conv != -42)
		return (conv_char(ap, printf_struct));
	if (printf_struct->conv == 'p')
		return (conv_pointer(ap, printf_struct));
	if (printf_struct->conv == 'd' || printf_struct->conv == 'i')
		return (conv_int(ap, printf_struct));
	if (printf_struct->conv == 'o')
		return (conv_oct(ap, printf_struct));
	if (printf_struct->conv == 'u')
		return (conv_unsint(ap, printf_struct));
	if (printf_struct->conv == 'x')
		return (conv_hex(ap, printf_struct));
	if (printf_struct->conv == 'X')
		return (capitalize(conv_hex(ap, printf_struct)));
	if (printf_struct->conv == 'f' || printf_struct->conv == 'F')
		return (conv_float(ap, printf_struct));
	if (printf_struct->conv == '%')
		return (conv_percent(printf_struct));
	return (exit_error("conv error", printf_struct));
}
