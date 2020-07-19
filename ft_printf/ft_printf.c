/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:23:43 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/19 03:13:43 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*exit_error(char *erinfo, t_printf *ps)
{
	ps->error = 1;
	return(ft_strdup(erinfo));
}

int		parse(int i, const char *input_str, va_list ap, t_printf ps)
{
	char	*res;

	res = NULL;
	i = parse_flags(input_str, ++i, &ps);
	res = conv_handler(ap, &ps);
	fix_flag_errors1(&ps);
	if (res)
		ps.res_len = ft_strlen(res);
	res = accuracy_and_size_handler(res, &ps);
	res = flags_handler(res, &ps);
	if (ps.conv == 'c' && ps.zero_arg && ps.is_minus)
		ft_putchar('\0');
	ps.ret_value += ft_putstr(res);
	if (ps.conv == 'c' && ps.zero_arg && !ps.is_minus)
		ft_putchar('\0');
	return (input_str[i] == '\0' ? i : i + 1);
}

int		ft_printf(const char *input_str, ...)
{
	va_list		ap;
	t_printf	ps;
	t_int		int_struct;
	int			i;

	i = 0;
	init(&ps, &int_struct);
	va_start(ap, input_str);
	while (input_str[i])
	{
		while (input_str[i] && input_str[i] != '%')
			ps.ret_value += ft_putchar(input_str[i++]);
		if (input_str[i])
		{
			i = parse(i, input_str, ap, ps);
			init_t_printf2(&ps);
		}
	}
	va_end(ap);
	return (ps.error ? -1 : ps.ret_value);
}
