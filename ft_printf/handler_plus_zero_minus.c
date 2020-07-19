/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_plus_zero_minus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:24:41 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/19 03:18:35 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*plus_handler25(char *res, t_printf *printf_struct)
{
	int	i;

	if (printf_struct->is_zero)
	{
		if (printf_struct->res_len < printf_struct->size)
			res[0] = '+';
		else if (printf_struct->res_len >= printf_struct->size)
			res = put_char_first(res, '+');
	}
	else
	{
		i = where_start(res, printf_struct);
		if (i > 0)
			res[--i] = '+';
		else if (i == 0)
			res = put_char_first(printf_struct->res, '+');
	}
	return (res);
}

char	*plus_handler(char *str, t_printf *ps)
{
	if (ps->accuracy && ps->size)
	{
		if (ps->size > ps->accuracy)
		{
			if (ps->res_len < ps->accuracy)
				str[ps->size - ps->accuracy - 1] = '+';
			else if ((ps->conv == 'f' || ps->conv == 'F') &&
						ps->size > ps->res_len)
				str[ps->size - ps->res_len - ps->is_point] = '+';
			else if (ps->res_len >= ps->accuracy)
				str = pcf_skip_sp(str, '+');
		}
		else if (ps->size <= ps->accuracy)
			str = put_char_first(str, '+');
	}
	else if (ps->size)
		str = plus_handler25(str, ps);
	else if (ps->accuracy)
		str = put_char_first(str, '+');
	else if (!ps->accuracy || !ps->size)
		str = put_char_first(str, '+');
	return (str);
}

char	*zero_handler(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			str[i] = '0';
	}
	return ((char*)str);
}

int		minus_handler25(char *res, t_printf *ps, int i)
{
	if (ps->conv == 's')
	{
		while ((unsigned long)i < ft_strlen(res) -
		(ps->is_space + ps->res_len))
			i++;
	}
	else
	{
		while (i < (int)ft_strlen(res) - ((ps->is_space || ps->is_plus) +
		(ps->res_len + ps->is_nan + ps->is_inf <
			ps->accuracy ? ps->accuracy :
			ps->res_len)) && res[i] == ' ')
			i++;
	}
	ps->res = res;
	return (i);
}

char	*minus_handler(char *res, t_printf *ps)
{
	int		i;
	int		j;
	char	*res1;
	char	*tmp;

	i = 0;
	j = 0;
	if (!(res1 = malloc(sizeof(char) * (ft_strlen(res) + 1))))
		return (exit_error("malloc unsuccessful", ps));
	i = minus_handler25(res, ps, i);
	while (res[i])
		res1[j++] = res[i++];
	while (i > j)
		res1[j++] = ' ';
	res1[j] = '\0';
	tmp = res1;
	free(tmp);
	return (res1);
}
