/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:23:25 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 19:23:28 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fix_flag_errors2(t_printf *ps)
{
	if (ps->is_space && (ps->conv == 'f' || ps->conv == 'F'))
		ps->is_zero = 0;
	if ((ps->accuracy || ps->is_minus) && ps->conv != 'f' && ps->conv != 'F')
		ps->is_zero = 0;
	if (ps->is_plus)
		ps->is_space = 0;
	if (ps->conv == 'c' || ps->conv == '%')
	{
		ps->accuracy = 0;
		ps->is_space = 0;
		ps->is_plus = 0;
	}
	if (ps->conv == 'p')
		ps->is_hash = 1;
}

void	fix_flag_errors1(t_printf *ps)
{
	if (ps->is_nan)
	{
		ps->is_plus = 0;
		ps->is_space = 0;
	}
	if (ps->is_plus && ps->conv == 'u')
		ps->is_plus = 0;
	if (ps->is_space && ps->conv == 'u')
		ps->is_space = 0;
	if (ps->zero_arg && ps->conv != 'f' && ps->conv != 'F')
		ps->is_hash = 0;
	if (ps->conv == 'x' || ps->conv == 'X' || ps->conv == 'p' ||
		ps->conv == 'o' || ps->conv == 's' || ps->conv == 'c')
	{
		ps->is_plus = 0;
		ps->is_space = 0;
	}
	fix_flag_errors2(ps);
}
