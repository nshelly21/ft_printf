#include "includes/ft_printf.h"

/* print all non-negative args one at a time;
   all args are assumed to be of int type */

/*void print_string(char *string)
{
	int i;

	i = 0;
	write(1, &string[i],ft_strlen(string));
}

char* reader_identifier(const char *string)
{
	char *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = (char*)malloc(sizeof(char)*ft_strlen(string));
	while(string[i] != '%')
	{
		tmp[i] = string[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}*/

// handle error!!!

char 	*conv_hex25(va_list ap, t_printf *printf_struct)
{
	t_int int_struct;

	init_t_int(&int_struct);
	if (printf_struct->is_hh)
	{
		int_struct.shortnb = (unsigned char)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 16));
	}
	return(NULL);
}

char 	*conv_hex(va_list ap, t_printf *printf_struct)
{
	t_int	int_struct;

	init_t_int(&int_struct);
	if (!(printf_struct->is_l && printf_struct->is_ll && printf_struct->is_h && printf_struct->is_hh))
	{
		int_struct.intnb = (unsigned int)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.intnb, 16));
	}
	if (printf_struct->is_l)
	{
		int_struct.intnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longnb, 16));
	}
	if (printf_struct->is_ll)
	{
		int_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longlongnb, 16));
	}
	if (printf_struct->is_h)
	{
		int_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 16));
	}
	return (conv_hex25(ap, printf_struct));
}

char	*conv_unsint25(va_list ap, t_printf *printf_struct)
{
	t_int int_struct;

	init_t_int(&int_struct);
	if (printf_struct->is_hh)
	{
		int_struct.shortnb = (unsigned char)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 10));
	}
	return(NULL);
}

char 	*conv_unsint(va_list ap, t_printf *printf_struct)
{
	t_int	int_struct;

	init_t_int(&int_struct);
	if (!(printf_struct->is_l && printf_struct->is_ll && printf_struct->is_h && printf_struct->is_hh))
	{
		int_struct.intnb = (unsigned int)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.intnb, 10));
	}
	if (printf_struct->is_l)
	{
		int_struct.intnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longnb, 10));
	}
	if (printf_struct->is_ll)
	{
		int_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longlongnb, 10));
	}
	if (printf_struct->is_h)
	{
		int_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 10));
	}
	return (conv_unsint25(ap, printf_struct));
}

char	*conv_oct25(va_list ap, t_printf *printf_struct)
{
	t_int int_struct;

	init_t_int(&int_struct);
	if (printf_struct->is_hh)
	{
		int_struct.shortnb = (unsigned char)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 8));
	}
	return(NULL);
}

char	*conv_oct(va_list ap, t_printf *printf_struct)
{
	t_int	int_struct;

	init_t_int(&int_struct);
	if (!(printf_struct->is_l && printf_struct->is_ll && printf_struct->is_h && printf_struct->is_hh))
	{
		int_struct.intnb = (unsigned int)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.intnb, 8));
	}
	if (printf_struct->is_l)
	{
		int_struct.intnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longnb, 8));
	}
	if (printf_struct->is_ll)
	{
		int_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 8));
	}
	if (printf_struct->is_h)
	{
		int_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 8));
	}
	return (conv_oct25(ap, printf_struct));
}

char	*conv_int25(va_list ap, t_printf *printf_struct)
{
	char    *res;
	t_int   int_struct;

	init_t_int(&int_struct);
	res = NULL;
	if (printf_struct->is_h == 1)
	{
		int_struct.shortnb = (short)va_arg(ap, int);
		return(ft_itoa_printf1((long long)int_struct.shortnb, 10, printf_struct));
	}
	if (printf_struct->is_hh == 1)
	{
		int_struct.shortnb = (char)va_arg(ap, int);
		return(ft_itoa_printf1((long long)int_struct.shortnb, 10, printf_struct));
	}
	return(res);
}

char    *conv_int(va_list ap, t_printf *printf_struct)
{
    t_int   int_struct;

	init_t_int(&int_struct);
	if (!(printf_struct->is_l && printf_struct->is_ll && printf_struct->is_h && printf_struct->is_hh))
	{
		int_struct.intnb = va_arg(ap, int);
		return(ft_itoa_printf1((long long) int_struct.intnb, 10, printf_struct));
	}
	if (printf_struct->is_l == 1 || printf_struct->is_ll == 1)
	{
		int_struct.longlongnb = va_arg(ap, long long);
		if (int_struct.longlongnb < 0)
			printf_struct->is_neg = 1;
		if (int_struct.longlongnb < -9223372036854775807 || int_struct.longlongnb > 9223372036854775807)
			return(ft_itoa_printf_u1((unsigned long long)int_struct.longlongnb, 10));
		else
			return(ft_itoa_printf1(int_struct.longlongnb, 10, printf_struct));
	}
    return(conv_int25(ap, printf_struct));
}
//TODO
char    *conv_string(va_list ap)
{
	char *identified_string;
	char *res;

	identified_string = va_arg(ap, typeof(identified_string));
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(identified_string) + 1))))
		return (0); //TODO write proper exit_error function
	res = ft_strcpy(res, identified_string);
	return (res);
}

void     conv_handler(va_list ap, int i, t_printf *printf_struct)
{
	if (printf_struct->conversion == 's')
		printf_struct->res = conv_string(ap);
	/*TODO else if (printf_struct->error_conv == 1 || printf_struct->conversion == 'c')
		printf_struct->res = conv_char(ap, printf_struct);*/
	if (printf_struct->conversion == 'd' || printf_struct->conversion == 'i')
        printf_struct->res = conv_int(ap, printf_struct);
    if (printf_struct->conversion == 'o')
        printf_struct->res = conv_oct(ap, printf_struct);
    if (printf_struct->conversion == 'u')
        printf_struct->res = conv_unsint(ap, printf_struct);
    if (printf_struct->conversion == 'x' || printf_struct->conversion == 'X')
        printf_struct->res = conv_hex(ap, printf_struct);
    if (printf_struct->conversion == 'f' || printf_struct->conversion == 'F')
        i = i + 0;
        //TODO printf_struct->res = conv_?(ap, printf_struct);
    if (printf_struct->conversion == '%')
        i = i + 0;
        //TODO printf_struct->res = conv_?(ap, printf_struct);
	// ft_putstr(printf_struct->res); NOTE not necessary anymore
	printf_struct->res_len = ft_strlen(printf_struct->res);
}

int 	init_flags(const char *str, int i, t_printf *printf_struct)
{
	while (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '#')
			printf_struct->is_hash = 1;
		if (str[i] == '0')
			printf_struct->is_zero = 1;
		if (str[i] == '-')
			printf_struct->is_minus = 1;
		if (str[i] == '+')
			printf_struct->is_plus = 1;
		i++;
	}
	return (i);
}

int 	is_flag(const char *str, int i)
{
	if (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '+' || str[i] == ' ')
		return (1);
	return (0);
}

int 	is_conv(const char *str, int i)
{
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' || str[i] == 'i' ||
	str[i] == 'o' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == 'f' || str[i] == '%')
		return (1);
	return (0);
}

int 	is_length(const char *str, int i)
{
	if (str[i] == 'h' || str[i] == 'l')
		return (1);
	return (0);
}

int 	count_dig(int nb)
{
	int dig;

	dig = 1;
	while (nb /= 10)
		dig++;
	return(dig);
}

int		init_accuracy(const char *input_str, int i, t_printf *printf_struct)
{
	if (printf_struct->is_point) //NOTE when is_point it is the accuracy
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

int		init_length(const char *input_str, int i, t_printf *printf_struct)
{
	if (input_str[i] == 'h')
		printf_struct->is_h = 1;
	if (input_str[i] == 'h' && input_str[i + 1] == 'h')
		printf_struct->is_hh = 1;
	if (input_str[i] == 'l')
		printf_struct->is_l = 1;
	if (input_str[i] == 'l' && input_str[i + 1] == 'l')
		printf_struct->is_ll = 1;
	return (i + (printf_struct->is_hh == 1 ? 2 : 0) + (printf_struct->is_ll == 1 ? 2 : 0) + printf_struct->is_l + printf_struct->is_h);
}

int		parse_flags(const char *input_str, int i, t_printf *printf_struct)
{
	if (is_flag(input_str, i))
		i = init_flags(input_str, i, printf_struct);
	if (ft_isdigit((int)input_str[i]))
		i = i + init_accuracy(input_str, i, printf_struct);
	if (input_str[i] == '.')
	{
		printf_struct->is_point = 1;
		if (input_str[++i] >= '0' && input_str[i] <= '9')
			i = init_accuracy(input_str, i, printf_struct); //NOTE when is_point it is the accuracy
		else
			printf_struct->accuracy = 0;
	}
	if (is_length(input_str, i))
		i = init_length(input_str, i, printf_struct);
	if (is_conv(input_str, i))
		printf_struct->conversion = input_str[i];
	else
		printf_struct->is_error_conv = 1; //TODO check how printf behaviours in this way
	return (i);
}

void 	accuracy_handler(t_printf *printf_struct)
{
	char 	*tmp;
	int 	i;
	int 	len;

	tmp = NULL;
	i = 0;
	len = printf_struct->accuracy - (int)ft_strlen(printf_struct->res);
	if (!(tmp = (char*)malloc(sizeof(char) * len + 1)))
		return ;
	while (i < len && printf_struct->conversion != 's')
		tmp[i++] = '0';
	tmp[i] = '\0';
	printf_struct->res = ft_strjoin(tmp, printf_struct->res);
	free(tmp);
}

void 	size_handler(t_printf *printf_struct)
{
	char 	*tmp;
	int 	i;
	int 	len;

	tmp = NULL;
	i = 0;
	len = printf_struct->size - (int)ft_strlen(printf_struct->res);
	if (!(tmp = (char*)malloc(sizeof(char) * len + 1)))
		return ;
	while (i < len)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	printf_struct->res = ft_strjoin(tmp, printf_struct->res);
	free(tmp);
}

void	accuracy_and_size_handler(t_printf *printf_struct)
{
	if (printf_struct->accuracy && (int)ft_strlen(printf_struct->res) < printf_struct->accuracy && (printf_struct->conversion != 'f' && printf_struct->conversion != 'F'))
		accuracy_handler(printf_struct);
	if (printf_struct->size && (int)ft_strlen(printf_struct->res) < printf_struct->size)
		size_handler(printf_struct);
}

char 	*put_char_first(char *str, char c)
{
	char 	*tmp;
	int 	i;

	tmp = NULL;
	i = -1;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (NULL);
	tmp[0] = c;
	while (str[++i])
		tmp[i + 1] = str[i];
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}

void 	hash_float_handler(char *str, t_printf *printf_struct)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] != '.')
		str[i] = '.';
	printf_struct->res = str;
}

void 	hash_oct_handler(char *str, t_printf *printf_struct)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (--i >= 0)
		str[i] = '0';
	else
		str = put_char_first(str, '0');
	printf_struct->res = str;
}

char	*hash_hex_handler25(char *str, char *res)
{
	if  (str[0] == '0' && str[1] == '0')
		str[1] = res[1];
	else if (str[0] == '0' && str[1] != '0')
	{
		str[0] = res[1];
		str = put_char_first(str, res[0]);
	}
	else if (str[0] != '0' && str[1] != res[1])
		str = put_char_first(str, res[1]);
	return (str);
}

void 	hash_hex_handler(char *str, t_printf *printf_struct)
{
	int		i;
	char	*res;

	i = 0;
	res = printf_struct->conversion == 'x' ? "0x" : "0X";
	while (str[i] == ' ')
		i++;
	if (--i > -1)
	{
		if (printf_struct->conversion == 'x' || printf_struct->conversion == 'X')
			str[i] = res[1];
	}
	else
	{
		if (printf_struct->size > printf_struct->accuracy)
			str = hash_hex_handler25(str, res);
		else if (printf_struct->size <= printf_struct->accuracy)
		{
			str = put_char_first(str, res[1]);
			str = put_char_first(str, res[0]);
		}
	}
	printf_struct->res = str;
}

//TODO подозрительно просто блядь. Посмотреть внимательнее.
void 	plus_handler25(t_printf *printf_struct)
{
	int	i;

	if (printf_struct->is_zero)
	{
		if (printf_struct->res_len < printf_struct->size)
			printf_struct->res[0] = ' ';
		else if (printf_struct->res_len >= printf_struct->size)
			printf_struct->res = put_char_first(printf_struct->res, ' ');
	}
	else
	{
		i = where_start(printf_struct);
		if (i > 0)
			printf_struct->res[--i] = ' ';
		else if (i == 0)
			printf_struct->res = put_char_first(printf_struct->res, ' ');
	}
}

void 	plus_handler(t_printf *printf_struct)
{
	if (printf_struct->accuracy || printf_struct->size)
	{
		if (printf_struct->accuracy > printf_struct->size)
		{
			if (printf_struct->res_len < printf_struct->accuracy)
				printf_struct->res[printf_struct->size - printf_struct->accuracy - 1] = ' ';
			else if ((printf_struct->conversion == 'f' || printf_struct->conversion == 'F') &&
					 printf_struct->size > printf_struct->res_len)
				printf_struct->res[printf_struct->size - printf_struct->res_len -
								   printf_struct->is_point] = ' ';
			else if (printf_struct->res_len >= printf_struct->accuracy)
				printf_struct->res = put_char_first(printf_struct->res, ' ');
		}
		else if (printf_struct->size <= printf_struct->accuracy)
			printf_struct->res = put_char_first(printf_struct->res, ' ');
	}
	else if (printf_struct->size)
		plus_handler25(printf_struct);
	else if (printf_struct->accuracy)
		printf_struct->res = put_char_first(printf_struct->res, ' ');
}

void 	zero_handler(char *str, t_printf *printf_struct)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			str[i] = '0';
	}
	printf_struct->res = str;
}

int 	where_start(t_printf *printf_struct)
{
	int i;

	i = 0;
	while ((printf_struct->res[i] == ' ' || printf_struct->res[i] == '0') &&
	i < (int)ft_strlen(printf_struct->res) - printf_struct->res_len)
		i++;
	return i;
}

void 	space_handler25(t_printf *printf_struct)
{
	int	i;

	if (printf_struct->is_zero)
	{
		if (printf_struct->res_len < printf_struct->size)
			printf_struct->res[0] = ' ';
		else if (printf_struct->res_len >= printf_struct->size)
			printf_struct->res = put_char_first(printf_struct->res, ' ');
	}
	else
	{
		i = where_start(printf_struct);
		if (i > 0)
			printf_struct->res[--i] = ' ';
		else if (i == 0)
			printf_struct->res = put_char_first(printf_struct->res, ' ');
	}
}

void 	space_handler(t_printf *printf_struct)
{
	if (printf_struct->accuracy || printf_struct->size)
	{
		if (printf_struct->accuracy > printf_struct->size)
		{
			if (printf_struct->res_len < printf_struct->accuracy)
				printf_struct->res[printf_struct->size - printf_struct->accuracy - 1] = ' ';
			else if ((printf_struct->conversion == 'f' || printf_struct->conversion == 'F') &&
			printf_struct->size > printf_struct->res_len)
				printf_struct->res[printf_struct->size - printf_struct->res_len -
				printf_struct->is_point] = ' ';
			else if (printf_struct->res_len >= printf_struct->accuracy)
				printf_struct->res = put_char_first(printf_struct->res, ' ');
		}
		else if (printf_struct->size <= printf_struct->accuracy)
			printf_struct->res = put_char_first(printf_struct->res, ' ');
	}
	else if (printf_struct->size)
		space_handler25(printf_struct);
	else if (printf_struct->accuracy)
		printf_struct->res = put_char_first(printf_struct->res, ' ');
}

void 	negnb_handler(t_printf *printf_struct)
{
	int	i;

	i = where_start(printf_struct);
	if (--i >= 0)
		printf_struct->res[i] = '-';
	else
	{
		if (printf_struct->res[0] == '0' && printf_struct->size > printf_struct->accuracy)
			printf_struct->res[0] = '-';
		else
			printf_struct->res = put_char_first(printf_struct->res, '-');
	}
}

void 	minus_handler(t_printf *printf_struct)
{
	int		i;
	int		j;
	char 	*res;

	i = 0;
	j = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(printf_struct->res) + 1))))
		return ;
	if (printf_struct->conversion == 's')
	{
		while (i < ft_strlen(printf_struct->res) - (printf_struct->is_space + printf_struct->res_len))
			i++;
	}
	else
	{
		while (i < (int)ft_strlen(printf_struct->res) - ((printf_struct->is_space || printf_struct->is_plus) +
						   (printf_struct->res_len < printf_struct->accuracy ? printf_struct->accuracy : printf_struct->res_len)) && printf_struct->res[i] == ' ')
			i++;
	}
	while (printf_struct->res[i])
		res[j++] = printf_struct->res[i++];
	while (i > j)
		res[j++] = ' ';
	res[j] = '\0';
	printf_struct->res = res;
	free(res);
}

void 	flags_handler(const char *str, t_printf *printf_struct)
{
	if (printf_struct->is_zero)
		zero_handler((char*)str, printf_struct);
	if (printf_struct->is_plus)
		plus_handler(printf_struct);
	if (printf_struct->is_space)
		space_handler(printf_struct);
	if ((printf_struct->conversion == 'x' || printf_struct->conversion == 'X') && printf_struct->is_hash)
		hash_hex_handler((char*)str, printf_struct);
	if (printf_struct->conversion == 'o' && !printf_struct->accuracy && printf_struct->is_hash)
		hash_oct_handler((char*)str, printf_struct);
	if ((printf_struct->conversion == 'f' || printf_struct->conversion == 'F') && printf_struct->is_hash)
		hash_float_handler((char*)str, printf_struct);
	if (printf_struct->is_neg)
		negnb_handler(printf_struct);
	if (printf_struct->is_minus)
		minus_handler(printf_struct);
	/*TODO handle inf, nan*/
}

void    init_t_printf(t_printf *printf_struct)
{
	printf_struct->conversion = 0;
	printf_struct->res = NULL;
	printf_struct->res_len = 0;
	printf_struct->is_neg = 0;
	printf_struct->iszero = 0;
	printf_struct->is_l = 0;
	printf_struct->is_ll = 0;
	printf_struct->is_h = 0;
	printf_struct->is_hh = 0;
	printf_struct->is_L = 0;
	printf_struct->is_hash = 0;
	printf_struct->is_zero = 0;
	printf_struct->is_minus = 0;
	printf_struct->is_plus = 0;
	printf_struct->is_space = 0;
	printf_struct->accuracy = 0;
	printf_struct->size = 0;
	printf_struct->is_point = 0;
	printf_struct->is_error_conv = 0;
}

void    init_t_int(t_int *int_struct)
{
	int_struct->longlongnb = 0;
	int_struct->longnb = 0;
	int_struct->intnb = 0;
	int_struct->shortnb = 0;
}

void init(t_printf *printf_struct, t_int *int_struct)
{
	init_t_printf(printf_struct);
	init_t_int(int_struct);
}

int		ft_printf(const char *input_str, ...)
{
	va_list		ap;
	int		res;
	t_printf	printf_struct;
	t_int       int_struct;
	int		i;

	i = 0;
	res = 0;
	init(&printf_struct, &int_struct);
	va_start(ap, input_str);
	while (input_str[i])
	{
		while (input_str[i] && input_str[i] != '%')
			res += ft_putchar(input_str[i++]);
		if (input_str[i])
		{
			i = parse_flags(input_str, ++i, &printf_struct);
			conv_handler(ap, i++, &printf_struct);
			accuracy_and_size_handler(&printf_struct);
			flags_handler(input_str, &printf_struct);
			ft_putstr(printf_struct.res);
			init_t_printf(&printf_struct);
		}
	}
	va_end(ap);
	write(1, "\n", 1); //TODO DELETE if not necessary
	return (res); //TODO return -1 if FATAL ERROR
}
