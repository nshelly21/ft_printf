/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:25:32 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/19 01:36:58 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*space_handler25(char *res, t_printf *printf_struct)
{
	int	i;

	if (printf_struct->is_zero)
	{
		if (printf_struct->res_len < printf_struct->size)
			res[0] = ' ';
		else if (printf_struct->res_len >= printf_struct->size)
			res = put_char_first(res, ' ');
	}
	else
	{
		i = where_start(res, printf_struct);
		if (i > 0)
			res[--i] = ' ';
		else if (i == 0)
			res = put_char_first(res, ' ');
	}
	return (res);
}

char	*space_handler(char *str, t_printf *ps)
{
	if (ps->accuracy && ps->size)
	{
		if (ps->size > ps->accuracy)
		{
			if (ps->res_len < ps->accuracy)
				str[ps->size - ps->accuracy - 1] = ' ';
			else if ((ps->conv == 'f' || ps->conv == 'F') &&
					 ps->size > ps->res_len)
				str[ps->size - ps->res_len - ps->is_point] = ' ';
			else if (ps->res_len >= ps->accuracy)
				str = pcf_skip_sp(str, ' ');
		}
		else if (ps->size <= ps->accuracy)
			str = put_char_first(str, ' ');
	}
	else if (ps->size)
		str = space_handler25(str, ps);
	else if (ps->accuracy)
		str = put_char_first(str, ' ');
	else if (!ps->accuracy || !ps->size)
		str = put_char_first(str, ' ');
	return (str);
}
