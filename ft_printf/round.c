/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:37:06 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/17 14:44:45 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

void	round1(t_printf *printf_struct)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (printf_struct->res[i + 1])
		i++;
	if (printf_struct->res[i--] >= '5')
		nb = 1;
	while (nb)
	{
		if (printf_struct->res[i] < '9' && printf_struct->res[i] != '.')
		{
			printf_struct->res[i] += 1;
			nb = 0;
		}
		else if (printf_struct->res[i] == '9')
			printf_struct->res[i] = '0';
		if (printf_struct->res[0] == '0')
		{
			printf_struct->res = put_char_first(printf_struct->res, '1');
			nb = 0;
		}
		i--;
	}
	round2(printf_struct);
}
