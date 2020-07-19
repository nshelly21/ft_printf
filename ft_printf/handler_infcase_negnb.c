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

char	*negnb_handler(char *str, t_printf *ps)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (--i >= 0)
		str[i] = '-';
	else
	{
		if (str[0] == '0' && ps->size > ps->accuracy && !ps->min_zero)
			str[0] = '-';
		else
			str = put_char_first(str, '-');
	}
	return (str);
}

char	*inf_case_handler(char *str, t_printf *ps)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (--i >= 0)
		str[i] = ps->is_plus ? '+' : ' ';
	else
		str = put_char_first(str, ps->is_plus ? '+' : ' ');
	return (str);
}

int		count_dig(int nb)
{
	int dig;

	dig = 1;
	while (nb /= 10)
		dig++;
	return (dig);
}
