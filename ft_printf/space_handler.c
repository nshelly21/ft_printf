/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:25:32 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/18 04:11:34 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	space_handler25(t_printf *printf_struct)
{
	int	i;

	if (printf_struct->is_zero)
	{
		if (printf_struct->res_len < printf_struct->size)
			printf_struct->res[0] = ' ';
		else if (printf_struct->res_len >= printf_struct->size)
			printf_struct->res = put_char_first(printf_struct->res, ' ');
	}
	else
	{
		i = where_start(printf_struct);
		if (i > 0)
			printf_struct->res[--i] = ' ';
		else if (i == 0)
			printf_struct->res = put_char_first(printf_struct->res, ' ');
	}
}

void	space_handler(t_printf *ps)
{
	if (ps->accuracy && ps->size)
	{
		if (ps->size > ps->accuracy)
		{
			if (ps->res_len < ps->accuracy)
				ps->res[ps->size - ps->accuracy - 1] = ' ';
			else if ((ps->conv == 'f' || ps->conv == 'F') &&
					ps->size > ps->res_len)
				ps->res[ps->size - ps->res_len -
						ps->is_point] = ' ';
			else if (ps->res_len >= ps->accuracy && (int)ft_strlen(ps->res) != ps->size)
				ps->res = put_char_first(ps->res, ' ');
		}
		else if (ps->size <= ps->accuracy)
			ps->res = put_char_first(ps->res, ' ');
	}
	else if (ps->size)
		space_handler25(ps);
	else if (ps->accuracy)
		ps->res = put_char_first(ps->res, ' ');
	else if (!ps->accuracy || !ps->size)
		ps->res = put_char_first(ps->res, ' ');
}
