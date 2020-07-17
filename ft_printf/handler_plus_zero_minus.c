/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_plus_zero_minus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:24:41 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 19:24:43 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	plus_handler25(t_printf *printf_struct)
{
	int	i;

	if (printf_struct->is_zero)
	{
		if (printf_struct->res_len < printf_struct->size)
			printf_struct->res[0] = '+';
		else if (printf_struct->res_len >= printf_struct->size)
			printf_struct->res = put_char_first(printf_struct->res, '+');
	}
	else
	{
		i = where_start(printf_struct);
		if (i > 0)
			printf_struct->res[--i] = '+';
		else if (i == 0)
			printf_struct->res = put_char_first(printf_struct->res, '+');
	}
}

void	plus_handler(t_printf *ps)
{
	if (ps->accuracy && ps->size)
	{
		if (ps->size > ps->accuracy)
		{
			if (ps->res_len < ps->accuracy)
				ps->res[ps->size - ps->accuracy - 1] = '+';
			else if ((ps->conv == 'f' || ps->conv == 'F') &&
						ps->size > ps->res_len)
				ps->res[ps->size - ps->res_len - ps->is_point] = '+';
			else if (ps->res_len >= ps->accuracy)
				ps->res = put_char_first(ps->res, '+');
		}
		else if (ps->size <= ps->accuracy)
			ps->res = put_char_first(ps->res, '+');
	}
	else if (ps->size)
		plus_handler25(ps);
	else if (ps->accuracy)
		ps->res = put_char_first(ps->res, '+');
	else if (!ps->accuracy || !ps->size)
		ps->res = put_char_first(ps->res, '+');
}

void	zero_handler(t_printf *printf_struct)
{
	int		i;

	i = -1;
	while (printf_struct->res[++i])
	{
		if (printf_struct->res[i] == ' ')
			printf_struct->res[i] = '0';
	}
}

void	minus_handler(t_printf *ps)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(ps->res) + 1))))
		return ;
	if (ps->conv == 's')
	{
		while ((unsigned long)i < ft_strlen(ps->res) - (ps->is_space + ps->res_len))
			i++;
	}
	else
	{
		while (i < (int)ft_strlen(ps->res) - ((ps->is_space || ps->is_plus) + (ps->res_len +
		ps->is_nan + ps->is_inf < ps->accuracy ? ps->accuracy : ps->res_len)) && ps->res[i] == ' ')
			i++;
	}
	while (ps->res[i])
		res[j++] = ps->res[i++];
	while (i > j)
		res[j++] = ' ';
	res[j] = '\0';
	ps->res = res;
	free(res);
}
