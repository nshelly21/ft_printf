/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_float_hex_oct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:24:07 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/19 01:13:55 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*hash_float_handler(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] != '.')
		str[i] = '.';
	return (str);
}

char	*float_handler(long double nb, t_printf *ps, char *res)
{
	int		i;
	char	*dot;
	char	*itoa;
	char 	*tmp;
	char	*tmp2;

	i = 0;
	res = ft_itoa_printf_u1((unsigned long long)nb, 10, ps);
	dot = ft_strnew(0);
	tmp = dot;
	while (++i <= ps->accuracy + 1)
	{
		nb = nb - (unsigned long long)nb;
		nb = nb * 10;
		itoa = ft_itoa_printf_u1((unsigned long long)nb, 10, ps);
		tmp2 = itoa;
		dot = ft_strjoin(dot, itoa);
		free_str(tmp, tmp2);
		tmp = dot;
	}
	dot = put_char_first(dot, '.');
	tmp = res;
	tmp2 = dot;
	res = round1(ps, ft_strjoin(res, dot));
	free_str(tmp, tmp2);
	return (res);
}

char	*hash_oct_handler(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (--i >= 0)
		str[i] = '0';
	else
		str = put_char_first(str, '0');
	return (str);
}

int		hash_hex_handler2525(char *hex, int j, t_printf *ps)
{
	if (ps->size > ps->accuracy)
	{
		if (ps->res[0] == '0' && ps->res[1] == '0' && j == 1)
			ps->res[1] = hex[1];
		else if (ps->res[0] == '0' && ps->res[1] != '0' && j == 1)
		{
			ps->res[0] = hex[1];
			ps->res = put_char_first(ps->res, hex[0]);
		}
		else if (ps->res[0] != '0' && ps->res[1] != hex[1])
			ps->res = put_char_first(ps->res, hex[j]);
	}
	else if (ps->size <= ps->accuracy)
	{
		ps->res = put_char_first(ps->res, hex[1]);
		ps->res = put_char_first(ps->res, hex[0]);
		return (1);
	}
	return (0);
}

char	*hash_hex_handler(char *str, t_printf *ps)
{
	int		i;
	int		j;
	char	*hex;

	i = 0;
	j = 2;
	hex = ps->conv == 'X' ? "0X" : "0x";
	while (str[i] == ' ')
		i++;
	while (--j >= 0)
	{
		if (--i >= 0)
		{
			if (ps->conv == 'x' || ps->conv == 'X' || ps->conv == 'p')
				str[i] = hex[j];
		}
		else
		{
			ps->res = str;
			if (hash_hex_handler2525(hex, j, ps))
				return (ps->res);
		}
	}
	return (str);
}
