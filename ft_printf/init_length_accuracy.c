/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_length_accuracy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:25:01 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 19:25:37 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_t_unsint(t_unsint *unsint_struct)
{
	unsint_struct->longlongnb = 0;
	unsint_struct->longnb = 0;
	unsint_struct->intnb = 0;
	unsint_struct->shortnb = 0;
}

int		init_accuracy(const char *input_str, int i, t_printf *printf_struct)
{
	if (printf_struct->is_point)
	{
		printf_struct->accuracy = ft_atoi(input_str + i);
		return (count_dig(printf_struct->accuracy));
	}
	else
	{
		printf_struct->size = ft_atoi(input_str + i);
		return (count_dig(printf_struct->size));
	}
}

int		init_length(const char *input_str, int i, t_printf *ps)
{
	if (input_str[i] == 'h' && input_str[i + 1] != 'h')
		ps->is_h = 1;
	if (input_str[i] == 'h' && input_str[i + 1] == 'h')
		ps->is_hh = 1;
	if (input_str[i] == 'l' && input_str[i + 1] != 'l')
		ps->is_l = 1;
	if (input_str[i] == 'l' && input_str[i + 1] == 'l')
		ps->is_ll = 1;
	return (i + (ps->is_hh ? 2 : 0) + (ps->is_ll == 1 ? 2 : 0) +
				ps->is_l + ps->is_h);
}
