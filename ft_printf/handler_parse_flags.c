/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_parse_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:24:29 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/19 00:52:51 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*flags_handler(char *str, t_printf *ps)
{
	if (!ps->is_nan && !ps->is_inf)
	{
		if (ps->is_zero)
			str = zero_handler(str);
		if (ps->is_plus && !ps->is_nan && !ps->is_neg)
			str = plus_handler(str, ps);
		if (ps->is_space && !ps->is_nan)
			str = space_handler(str, ps);
		if (ps->is_hash == 1 && (ps->conv == 'x' ||
			ps->conv == 'X' || ps->conv == 'p') &&
			!((ps->conv == 'x' || ps->conv == 'X') && ps->zero_arg == 1))
			str = hash_hex_handler(str, ps);
		if (ps->conv == 'o' && !ps->accuracy && ps->is_hash)
			str = hash_oct_handler(str);
		if (ps->is_neg)
			str = negnb_handler(str, ps);
		if ((ps->conv == 'f' || ps->conv == 'F') && ps->is_hash)
			hash_float_handler(str);
	}
	if (ps->is_inf && (ps->is_plus || ps->is_space))
		str = inf_case_handler(str, ps);
	if (ps->is_minus)
		str = minus_handler(str, ps);
	return (str);
}

int		parse_flags(const char *input_str, int i, t_printf *printf_struct)
{
	if (is_flag(input_str, i))
		i = init_flags(input_str, i, printf_struct);
	if (ft_isdigit((int)input_str[i]))
		i = i + init_accuracy(input_str, i, printf_struct);
	if (input_str[i] == '.')
	{
		printf_struct->is_point = 1;
		while (!is_conv(input_str, i) || !input_str[i])
			if (is_length(input_str, i))
				i = init_length(input_str, i, printf_struct);
			else if (input_str[++i] >= '0' && input_str[i] <= '9')
				i = i + init_accuracy(input_str, i, printf_struct);
			else if (!is_conv(input_str, i))
				printf_struct->accuracy = 0;
	}
	else
		printf_struct->accuracy = 0;
	if (is_length(input_str, i))
		i = init_length(input_str, i, printf_struct);
	if (is_conv(input_str, i))
		printf_struct->conv = input_str[i];
	else
	{
		printf_struct->error_conv = input_str[i];
		printf_struct->conv = 'c';
	}
	return (i);
}
