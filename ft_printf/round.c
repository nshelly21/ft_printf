/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:37:06 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/19 00:23:14 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*round2(t_printf *printf_struct, char *res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i] != '.')
		i++;
	j = i;
	while (i - j < printf_struct->accuracy)
		i++;
	res[i + 1] = '\0';
	if (res[i] == '.')
		res[i] = '\0';
	return (res);
}

int		round25(int i, int nb, char *res)
{
	if (res[i] < '9' && res[i] != '.')
	{
		res[i] += 1;
		nb = 0;
	}
	else if (res[i] == '9')
		res[i] = '0';
	return (nb);
}

char	*round1(t_printf *ps, char *res)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (res[i + 1])
		i++;
	if (res[i--] >= '5')
		nb = 1;
	while (nb)
	{
		nb = round25(i, nb, res);
		i--;
	}
	return(round2(ps, res));
}
