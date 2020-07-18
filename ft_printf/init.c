/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:24:54 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 19:25:37 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_t_int(t_int *int_struct)
{
	int_struct->longlongnb = 0;
	int_struct->longnb = 0;
	int_struct->intnb = 0;
	int_struct->shortnb = 0;
}

void	init_t_printf2(t_printf *printf_struct)
{
	printf_struct->conv = 0;
	printf_struct->res_len = 0;
	printf_struct->is_neg = 0;
	printf_struct->is_l = 0;
	printf_struct->is_ll = 0;
	printf_struct->is_h = 0;
	printf_struct->is_hh = 0;
	printf_struct->is_hash = 0;
	printf_struct->is_zero = 0;
	printf_struct->is_minus = 0;
	printf_struct->is_plus = 0;
	printf_struct->is_space = 0;
	printf_struct->accuracy = 0;
	printf_struct->is_point = 0;
	printf_struct->error_conv = -42;
	printf_struct->zero_arg = 0;
	printf_struct->is_nan = 0;
	printf_struct->is_inf = 0;
	printf_struct->error = 0;
	printf_struct->min_zero = 0;
}

void	init_t_printf1(t_printf *printf_struct)
{
	printf_struct->res = NULL;
	printf_struct->ret_value = 0;
	printf_struct->size = 0;
	init_t_printf2(printf_struct);
}

void	init(t_printf *printf_struct, t_int *int_struct)
{
	init_t_printf1(printf_struct);
	init_t_int(int_struct);
}

int		init_flags(const char *str, int i, t_printf *printf_struct)
{
	while (str[i] == '#' || str[i] == '0' || str[i] == '-'
			|| str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '#')
			printf_struct->is_hash = 1;
		if (str[i] == '0')
			printf_struct->is_zero = 1;
		if (str[i] == '-')
			printf_struct->is_minus = 1;
		if (str[i] == '+')
			printf_struct->is_plus = 1;
		if (str[i] == ' ')
			printf_struct->is_space = 1;
		i++;
	}
	return (i);
}
