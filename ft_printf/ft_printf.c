#include "includes/ft_printf.h"

int		ft_printf(const char *input_str, ...)
{
	va_list		ap;
	t_printf	printf_struct;
	t_int       int_struct;
	int		i;

	i = 0;
	init(&printf_struct, &int_struct);
	va_start(ap, input_str);
	while (input_str[i])
	{
		while (input_str[i] && input_str[i] != '%')
			printf_struct.ret_value += ft_putchar(input_str[i++]);
		if (input_str[i])
		{
			i = parse_flags(input_str, ++i, &printf_struct);
			conv_handler(ap, &printf_struct);
			fix_flag_errors(&printf_struct);
			accuracy_and_size_handler(&printf_struct);
			flags_handler(printf_struct.res, &printf_struct);
			if (printf_struct.conversion == 'c' && printf_struct.zero_arg  && printf_struct.is_minus)
				ft_putchar('\0');
			printf_struct.ret_value += ft_putstr(printf_struct.res);
			if (printf_struct.conversion == 'c' && printf_struct.zero_arg && !printf_struct.is_minus)
				ft_putchar('\0');
			init_t_printf2(&printf_struct);
			i = input_str[i] == '\0' ? i : i + 1;
		}
	}
	va_end(ap);
	return (printf_struct.ret_value); //TODO return -1 if FATAL ERROR
}
