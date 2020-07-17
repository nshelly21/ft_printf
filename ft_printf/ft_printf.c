/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:23:43 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 20:14:15 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	exit_error(t_printf *ps)
{
	ps->error = 1;
}

int		parse(int i, const char *input_str, va_list ap, t_printf ps)
{
	i = parse_flags(input_str, ++i, &ps);
	conv_handler(ap, &ps);
	fix_flag_errors1(&ps);
	accuracy_and_size_handler(&ps);
	flags_handler(ps.res, &ps);
	if (ps.conv == 'c' && ps.zero_arg && ps.is_minus)
		ft_putchar('\0');
	ps.ret_value += ft_putstr(ps.res);
	if (ps.conv == 'c' && ps.zero_arg && !ps.is_minus)
		ft_putchar('\0');
	init_t_printf2(&ps);
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
			i = parse(i, input_str, ap, ps);
	}
	va_end(ap);
	return (ps.error ? -1 : ps.ret_value);
}
