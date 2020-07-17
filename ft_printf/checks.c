/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nshelly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:02:00 by nshelly           #+#    #+#             */
/*   Updated: 2020/07/17 13:25:26 by nshelly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_flag(const char *str, int i)
{
	if (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '+' \
			|| str[i] == ' ')
		return (1);
	return (0);
}

int	is_conv(const char *str, int i)
{
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' || \
			str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] \
			== 'x' || str[i] == 'X' || str[i] == 'f' || str[i] == '%')
		return (1);
	return (0);
}

int	is_length(const char *str, int i)
{
	if (str[i] == 'h' || str[i] == 'l')
		return (1);
	return (0);
}
