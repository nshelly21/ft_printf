/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_float_hex_oct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:24:07 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 19:24:09 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hash_float_handler(char *str, t_printf *printf_struct)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] != '.')
		str[i] = '.';
	printf_struct->res = str;
}

void	float_handler(long double nb, t_printf *ps)
{
	int		i;
	char	*dot;
	char	*tmp;

	i = 0;
	ps->res = ft_itoa_printf_u1((unsigned long long)nb, 10, ps);
	dot = ft_strnew(0);
	while (++i <= ps->accuracy + 1)
	{
		nb = nb - (unsigned long long)nb;
		nb = nb * 10;
		tmp = ft_itoa_printf_u1((unsigned long long)nb, 10, ps);
		dot = ft_strjoin(dot, tmp);
	}
	dot = put_char_first(dot, '.');
	ps->res = ft_strjoin(ps->res, dot);
	round1(ps);
}

void	hash_oct_handler(char *str, t_printf *printf_struct)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (--i >= 0)
		str[i] = '0';
	else
		printf_struct->res = put_char_first(printf_struct->res, '0');
}

void	hash_hex_handler25(char *hex, int j, t_printf *ps)
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

void	hash_hex_handler(t_printf *ps)
{
	int		i;
	int		j;
	char	*hex;

	i = 0;
	j = 2;
	hex = ps->conv == 'X' ? "0X" : "0x";
	while (ps->res[i] == ' ')
		i++;
	while (--j >= 0)
	{
		if (--i >= 0)
		{
			if (ps->conv == 'x' || ps->conv == 'X' || ps->conv == 'p')
				ps->res[i] = hex[j];
		}
		else
		{
			if (ps->size > ps->accuracy)
				hash_hex_handler25(hex, j, ps);
			else if (ps->size <= ps->accuracy)
			{
				ps->res = put_char_first(ps->res, hex[1]);
				ps->res = put_char_first(ps->res, hex[0]);
				break ;
			}
		}
	}
}

