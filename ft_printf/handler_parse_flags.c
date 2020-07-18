/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_parse_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:24:29 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/18 05:03:48 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flags_handler(const char *str, t_printf *ps)
{
	if (!ps->is_nan && !ps->is_inf)
	{
		if (ps->is_zero)
			zero_handler(ps);
		if (ps->is_plus && !ps->is_nan && !ps->is_neg)
			plus_handler(ps);
		if (ps->is_space && !ps->is_nan)
			space_handler(ps);
		if (ps->is_hash == 1 && (ps->conv == 'x' ||
			ps->conv == 'X' || ps->conv == 'p') &&
			!((ps->conv == 'x' || ps->conv == 'X') && ps->zero_arg == 1))
			hash_hex_handler(ps);
		if (ps->conv == 'o' && !ps->accuracy && ps->is_hash)
			hash_oct_handler((char*)str, ps);
		if (ps->is_neg)
			negnb_handler(ps);
		if ((ps->conv == 'f' || ps->conv == 'F') && ps->is_hash)
			hash_float_handler(ps->res, ps);
	}
	if (ps->is_inf && (ps->is_plus || ps->is_space))
		inf_case_handler(ps);
	if (ps->is_minus)
		minus_handler(ps);
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
