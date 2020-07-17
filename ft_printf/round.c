/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:37:06 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/17 20:24:31 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	round2(t_printf *printf_struct)
{
	int	i;
	int	j;

	i = 0;
	while (printf_struct->res[i] != '.')
		i++;
	j = i;
	while (i - j < printf_struct->accuracy)
		i++;
	printf_struct->res[i + 1] = '\0';
	if (printf_struct->res[i] == '.')
		printf_struct->res[i] = '\0';
}

int		round25(t_printf *ps, int i, int nb)
{
	if (ps->res[i] < '9' && ps->res[i] != '.')
	{
		ps->res[i] += 1;
		nb = 0;
	}
	else if (ps->res[i] == '9')
		ps->res[i] = '0';
	if (ps->res[0] == '0')
	{
		ps->res = put_char_first(ps->res, '1');
		nb = 0;
	}
	return (nb);
}

void	round1(t_printf *ps)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (ps->res[i + 1])
		i++;
	if (ps->res[i--] >= '5')
		nb = 1;
	while (nb)
	{
		nb = round25(ps, i, nb);
		i--;
	}
	round2(ps);
}
