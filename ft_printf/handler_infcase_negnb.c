/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_infcase_negnb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:24:18 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 19:27:40 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	negnb_handler(t_printf *ps)
{
	int	i;

	i = 0;
	while (ps->res[i] == ' ')
		i++;
	if (--i >= 0)
		ps->res[i] = '-';
	else
	{
		if (ps->res[0] == '0' && ps->size > ps->accuracy)
			ps->res[0] = '-';
		else
			ps->res = put_char_first(ps->res, '-');
	}
}

void	inf_case_handler(t_printf *ps)
{
	int	i;

	i = 0;
	while (ps->res[i] == ' ')
		i++;
	if (--i >= 0)
		ps->res[i] = ps->is_plus ? '+' : ' ';
	else
		ps->res = put_char_first(ps->res, ps->is_plus ? '+' : ' ');
}

int		count_dig(int nb)
{
	int dig;

	dig = 1;
	while (nb /= 10)
		dig++;
	return (dig);
}
