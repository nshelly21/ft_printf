/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_accuracy_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:23:51 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/19 02:58:05 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*accuracy_handler(char *res, t_printf *printf_struct)
{
	char	*res1;
	char	*tmp;
	int		i;
	int		len;

	tmp = res;
	i = 0;
	len = 0;
	if (res)
		len = printf_struct->accuracy - (int)ft_strlen(res);
	if (!(res1 = (char*)malloc(sizeof(char) * len + 1)))
		return (exit_error("malloc unsuccessful", printf_struct));
	while (i < len && printf_struct->conv != 's')
		res1[i++] = '0';
	res1[i] = '\0';
	res = ft_strjoin(res1, res);
	free(tmp);
	free(res1);
	return (res);
}

char	*size_handler(char *res, t_printf *printf_struct)
{
	char	*res1;
	int		i;
	int		len;

	i = -1;
	len = 0;
	if (printf_struct->conv == 'c' && printf_struct->zero_arg)
		printf_struct->size -= 1;
	if (res)
		len = printf_struct->size - (int)ft_strlen(res);
	if (!(res1 = (char*)malloc(sizeof(char) * len + 1)))
		return (exit_error("malloc unsuccessful", printf_struct));
	while (++i < len)
		res1[i] = ' ';
	res1[i] = '\0';
	res = ft_strjoin(res1, res);
	free(res1);
	return (res);
}

char	*accuracy_and_size_handler(char *res, t_printf *ps)
{
	if (ps->accuracy && (int)ft_strlen(res) < ps->accuracy &&
	(ps->conv != 'f' && ps->conv != 'F'))
		res = accuracy_handler(res, ps);
	if (ps->size && (int)ft_strlen(res) < ps->size)
		res = size_handler(res, ps);
	return (res);
}
