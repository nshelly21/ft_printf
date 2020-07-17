/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_string_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:23:06 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 19:23:12 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*conv_string(va_list ap, t_printf *ps)
{
	char	*str;
	char	*res;
	int		i;

	i = -1;
	str = va_arg(ap, typeof(str));
	if (!str && !ps->is_point)
		return (ft_strdup("(null)"));
	if (!ps->accuracy && ps->is_point)
		return (ft_strnew(0));
	if (!ps->accuracy)
	{
		if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (0); //TODO write proper exit_error function
		res = ft_strcpy(res, str);
	}
	else
	{
		if (!(res = (char*)malloc(sizeof(char) * (ps->accuracy + 1))))
			return (0);
		while (++i < ps->accuracy)
			res[i] = str[i];
		res[i] = '\0';
	}
	return (res);
}

char	*conv_char(va_list ap, t_printf *ps)
{
	char identified_char;
	char *res;

	if (ps->error_conv == -42)
		identified_char = va_arg(ap, int);
	elseasd
		identified_char = ps->error_conv;
	if (identified_char == 0)
	{
		ps->zero_arg = 1;
		if (ps->error_conv == -42)
			ps->ret_value += 1;
		return (ft_strnew(0));
	}
	if (!(res = (char*)malloc(sizeof(char) * 2)))
		return (0); //TODO write proper exit_error function
	res[0] = identified_char;
	res[1] = '\0';
	return (res);
}
