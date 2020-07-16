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

void    init_t_int(t_int *int_struct)
{
	int_struct->longlongnb = 0;
	int_struct->longnb = 0;
	int_struct->intnb = 0;
	int_struct->shortnb = 0;
}

void    init_t_unsint(t_unsint *unsint_struct)
{
	unsint_struct->longlongnb = 0;
	unsint_struct->longnb = 0;
	unsint_struct->intnb = 0;
	unsint_struct->shortnb = 0;
}

char 	*conv_hex25(va_list ap, t_printf *printf_struct, t_unsint unsint_struct)
{
		if (printf_struct->is_hh)
	{
		unsint_struct.shortnb = (unsigned char)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.shortnb, 16, printf_struct));
	}
	return(NULL);
}

char 	*conv_hex(va_list ap, t_printf *printf_struct)
{
	t_unsint	unsint_struct;

	init_t_unsint(&unsint_struct);
	if (printf_struct->is_l)
	{
		unsint_struct.longnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.longnb, 16, printf_struct));
	}
	if (!(printf_struct->is_l || printf_struct->is_ll || printf_struct->is_h || printf_struct->is_hh))
	{
		unsint_struct.intnb = (unsigned int)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.intnb, 16, printf_struct));
	}
	if (printf_struct->is_ll)
	{
		unsint_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.longlongnb, 16, printf_struct));
	}
	if (printf_struct->is_h)
	{
		unsint_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.shortnb, 16, printf_struct));
	}
	return (conv_hex25(ap, printf_struct, unsint_struct));
}

char	*conv_unsint25(va_list ap, t_printf *printf_struct, t_unsint int_struct)
{
	if (printf_struct->is_hh)
	{
		int_struct.shortnb = (unsigned char)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 10, printf_struct));
	}
	return(NULL);
}

char 	*conv_unsint(va_list ap, t_printf *printf_struct)
{
	t_unsint	unsint_struct;

	init_t_unsint(&unsint_struct);
	if (!(printf_struct->is_l || printf_struct->is_ll || printf_struct->is_h || printf_struct->is_hh))
	{
		unsint_struct.intnb = (unsigned int)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.intnb, 10, printf_struct));
	}
	if (printf_struct->is_l)
	{
		unsint_struct.longnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.longnb, 10, printf_struct));
	}
	if (printf_struct->is_ll)
	{
		unsint_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.longlongnb, 10, printf_struct));
	}
	if (printf_struct->is_h)
	{
		unsint_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.shortnb, 10, printf_struct));
	}
	return (conv_unsint25(ap, printf_struct, unsint_struct));
}

char	*conv_oct25(va_list ap, t_printf *printf_struct, t_unsint unsint_struct)
{
	if (printf_struct->is_hh)
	{
		unsint_struct.shortnb = (unsigned char)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.shortnb, 8, printf_struct));
	}
	return(NULL);
}

char	*conv_oct(va_list ap, t_printf *printf_struct)
{
	t_unsint	unsint_struct;

	init_t_unsint(&unsint_struct);
	if (!(printf_struct->is_l || printf_struct->is_ll || printf_struct->is_h || printf_struct->is_hh))
	{
		unsint_struct.intnb = (unsigned int)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.intnb, 8, printf_struct));
	}
	if (printf_struct->is_l)
	{
		unsint_struct.longnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.longnb, 8, printf_struct));
	}
	if (printf_struct->is_ll)
	{
		unsint_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.longlongnb, 8, printf_struct));
	}
	if (printf_struct->is_h)
	{
		unsint_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)unsint_struct.shortnb, 8, printf_struct));
	}
	return (conv_oct25(ap, printf_struct, unsint_struct));
}

char	*conv_int25(va_list ap, t_printf *printf_struct)
{
	char    *res;
	t_int   int_struct;

	init_t_int(&int_struct);
	res = NULL;
	if (!(printf_struct->is_l && printf_struct->is_ll && printf_struct->is_h && printf_struct->is_hh))
	{
		int_struct.intnb = va_arg(ap, int);
		return(ft_itoa_printf1((long long) int_struct.intnb, 10, printf_struct));
	}
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
	if (printf_struct->is_l == 1 || printf_struct->is_ll == 1)
	{
		int_struct.longlongnb = va_arg(ap, long long);
		if (int_struct.longlongnb < 0)
		{
			printf_struct->is_plus = 0;
			printf_struct->is_neg = 1;
		}
		if (int_struct.longlongnb < -9223372036854775807 || int_struct.longlongnb > 9223372036854775807)
			return(ft_itoa_printf_u1((unsigned long long)int_struct.longlongnb, 10, printf_struct));
		else
			return(ft_itoa_printf1(int_struct.longlongnb, 10, printf_struct));
	}
    return(conv_int25(ap, printf_struct));
}

char    *conv_string(va_list ap, t_printf *printf_struct)
{
	char	*identified_string;
	char	*res;
	int 	i;

	i = -1;
	identified_string = va_arg(ap, typeof(identified_string));
	if (!identified_string && !printf_struct->is_point)
		return (ft_strdup("(null)"));
	if (!printf_struct->accuracy && printf_struct->is_point)
		return (ft_strnew(0));
	if (!printf_struct->accuracy)
	{
		if (!(res = (char *) malloc(sizeof(char) * (ft_strlen(identified_string) + 1))))
			return (0); //TODO write proper exit_error function
		res = ft_strcpy(res, identified_string);
	}
	else
	{
		if (!(res = (char *) malloc(sizeof(char) * (printf_struct->accuracy + 1))))
			return (0);
		while (++i < printf_struct->accuracy)
			res[i] = identified_string[i];
		res[i] = '\0';
	}
	return (res);
}

/*char	*ft_charcpy(char *dest, const char src)
{
	dest[0] = src;
	dest[1] = '\0';
	return (dest);
}*/

char    *conv_char(va_list ap, t_printf *printf_struct)
{
	char identified_char;
	char *res;

	if (printf_struct->error_conv == -42)
		identified_char = va_arg(ap, int);
	else
		identified_char = printf_struct->error_conv;
	if (identified_char == 0)
	{
		printf_struct->zero_arg = 1;
		if (printf_struct->error_conv == -42)
			printf_struct->ret_value += 1;
		return (ft_strnew(0));
	}
	if (!(res = (char*)malloc(sizeof(char) * 2)))
		return (0); //TODO write proper exit_error function
	res[0] = identified_char;
	res[1] = '\0';
	return (res);
}

void    conv_pointer(va_list ap, t_printf *printf_struct)
{
	void		*str;
	long long	k;

	str = va_arg(ap, void*);
	k = (long long)str;
	printf_struct->res = ft_itoa_printf1(k, 16, printf_struct);
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
	//free(str);
	return (tmp);
}

void 	round2(t_printf *printf_struct)
{
	int	i;
	int j;

	i = 0;
	while (printf_struct->res[i] != '.')
		i++;
	j = i;
	while (i - j < printf_struct->accuracy)
		i++;
	printf_struct->res[i + 1] = '\0';
	if (printf_struct->res[i] == '.')
		printf_struct->res[i] = '\0';
}

void 	round1(t_printf *printf_struct)
{
	int	i;
	int nb;

	i = 0;
	nb = 0;
	while (printf_struct->res[i + 1])
		i++;
	if (printf_struct->res[i] >= '5')
		nb = 1;
	i--;
	while (nb)
	{
		if (printf_struct->res[i] < '9' && printf_struct->res[i] != '.') {
			printf_struct->res[i] += 1;
			nb = 0;
		}
		else if (printf_struct->res[i] == '9')
			printf_struct->res[i] = '0';
		if (printf_struct->res[0] == '0')
		{
			printf_struct->res = put_char_first(printf_struct->res, '1');
			nb = 0;
		}
		i--;
	}
	round2(printf_struct);
}

void	float_handler(long double nb, t_printf *printf_struct)
{
	int		i;
	char	*dot;
	char 	*tmp;

	i = 0;
	printf_struct->res = ft_itoa_printf_u1((unsigned long long)nb, 10, printf_struct);
	dot = ft_strnew(0);
	while (++i <= printf_struct->accuracy + 1)
	{
		nb = nb - (unsigned long long)nb;
		nb = nb * 10;
		tmp = ft_itoa_printf_u1((unsigned long long)nb, 10, printf_struct);
		dot = ft_strjoin(dot, tmp);
	}
	dot = put_char_first(dot, '.');
	printf_struct->res = ft_strjoin(printf_struct->res, dot);
	round1(printf_struct);
}

void 	conv_float(va_list ap, t_printf *ps)
{
	long double	nb;

	nb = (long double)va_arg(ap, double);
	if (!(ps->accuracy) && !(ps->is_point))
		ps->accuracy = 6;
	if ((1.0 / 0.0) == nb)
	{
		ps->is_inf = 1;
		ps->res = (ps->conversion == 'f' ? "inf" : "INF");
		return ;
	}
	if (nb < 0)
	{
		ps->is_neg = 1;
		nb = nb * (-1);
	}
	float_handler(nb, ps);
}

char	*capitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

void 	conv_percent( t_printf *printf_struct)
{
	if (!(printf_struct->res = malloc(sizeof(char) * 2)))
		return ;
	printf_struct->res[0] = '%';
	printf_struct->res[1] = '\0';
}

void     conv_handler(va_list ap, t_printf *printf_struct)
{
	if (printf_struct->conversion == 's')
		printf_struct->res = conv_string(ap, printf_struct);
	if (printf_struct->conversion == 'c' || printf_struct->error_conv != -42)
		printf_struct->res = conv_char(ap, printf_struct);
	if (printf_struct->conversion == 'p')
		conv_pointer(ap, printf_struct);
	if (printf_struct->conversion == 'd' || printf_struct->conversion == 'i')
        printf_struct->res = conv_int(ap, printf_struct);
    if (printf_struct->conversion == 'o')
		printf_struct->res = conv_oct(ap, printf_struct);
    if (printf_struct->conversion == 'u')
        printf_struct->res = conv_unsint(ap, printf_struct);
    if (printf_struct->conversion == 'x')
		printf_struct->res = conv_hex(ap, printf_struct);
    if (printf_struct->conversion == 'X')
    	printf_struct->res = capitalize(conv_hex(ap, printf_struct));
    if (printf_struct->conversion == 'f')
        conv_float(ap, printf_struct);
    if (printf_struct->conversion == 'F')
		printf_struct->res = capitalize(conv_hex(ap, printf_struct));
    if (printf_struct->conversion == '%')
	    conv_percent(printf_struct);
	if (printf_struct->res)
		printf_struct->res_len = ft_strlen(printf_struct->res);
}

int 	init_flags(const char *str, int i, t_printf *printf_struct)
{
	while (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '#')
			printf_struct->is_hash = 1;
		if (str[i] == '0')
			printf_struct->is_zero = 1;
		if (str[i] == '-')
			printf_struct->is_minus = 1;
		if (str[i] == '+')
			printf_struct->is_plus = 1;
		if (str[i] == ' ')
			printf_struct->is_space = 1;
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
	if (input_str[i] == 'h' && input_str[i + 1] != 'h')
		printf_struct->is_h = 1;
	if (input_str[i] == 'h' && input_str[i + 1] == 'h')
		printf_struct->is_hh = 1;
	if (input_str[i] == 'l' && input_str[i + 1] != 'l')
		printf_struct->is_l = 1;
	if (input_str[i] == 'l' && input_str[i + 1] == 'l')
		printf_struct->is_ll = 1;
	return (i + (printf_struct->is_hh ? 2 : 0) + (printf_struct->is_ll == 1 ? 2 : 0) + printf_struct->is_l + printf_struct->is_h);
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
			i = i + init_accuracy(input_str, i, printf_struct); //NOTE when is_point it is the accuracy
		else
			printf_struct->accuracy = 0;
	}
	else
		printf_struct->accuracy = 0;
	if (is_length(input_str, i))
		i = init_length(input_str, i, printf_struct); //TODO CHECK PLEASE
	if (is_conv(input_str, i))
		printf_struct->conversion = input_str[i];
	else
	{
		printf_struct->error_conv = input_str[i];
		printf_struct->conversion = 'c';
	}
	return (i);
}

void 	accuracy_handler(t_printf *printf_struct)
{
	char 	*tmp;
	int 	i;
	int 	len;

	tmp = NULL;
	i = 0;
	len = 0;
	if (printf_struct->res)
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

	tmp = printf_struct->res;
	i = 0;
	len = 0;
	if (printf_struct->conversion == 'c' && printf_struct->zero_arg)
		printf_struct->size -= 1;
	if (printf_struct->res)
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
		printf_struct->res = put_char_first(printf_struct->res, '0');
}

void	hash_hex_handler25(char *hex, int j, t_printf *printf_struct)
{
	if  (printf_struct->res[0] == '0' && printf_struct->res[1] == '0' && j == 1)
		printf_struct->res[1] = hex[1];
	else if (printf_struct->res[0] == '0' && printf_struct->res[1] != '0' && j == 1)
	{
		printf_struct->res[0] = hex[1];
		printf_struct->res = put_char_first(printf_struct->res, hex[0]);
	}
	else if (printf_struct->res[0] != '0' && printf_struct->res[1] != hex[1])
		printf_struct->res = put_char_first(printf_struct->res, hex[j]);
}

void 	hash_hex_handler(t_printf *printf_struct)
{
	int		i;
	int 	j;
	char 	*hex;

	i = 0;
	j = 2;
	hex = printf_struct->conversion == 'X' ? "0X" : "0x";
	while (printf_struct->res[i] == ' ')
			i++;
	while (--j >= 0)
	{
		if (--i >= 0)
		{
			if (printf_struct->conversion == 'x' || printf_struct->conversion == 'X'
			|| printf_struct->conversion == 'p')
				printf_struct->res[i] = hex[j];
		}
		else
		{
			if (printf_struct->size > printf_struct->accuracy)
				hash_hex_handler25(hex, j, printf_struct);
			else if (printf_struct->size <= printf_struct->accuracy)
			{
				printf_struct->res = put_char_first(printf_struct->res, hex[1]);
				printf_struct->res = put_char_first(printf_struct->res, hex[0]);
				break ;
			}
		}
	}
}

/*void 	hash_hex_handler(char *str, t_printf *printf_struct)
{
	//int		i;
	char	res;

	//i = 0;
	res = printf_struct->conversion == 'x' ? 'x' : 'X';
	*//*while (str[i] == ' ')
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
	}*//*
	str = put_char_first(printf_struct->res, res);
	str = put_char_first(str, '0');
	printf_struct->res = str;
}*/

//TODO подозрительно просто блядь. Посмотреть внимательнее.
void 	plus_handler25(t_printf *printf_struct)
{
	int	i;

	if (printf_struct->is_zero)
	{
		if (printf_struct->res_len < printf_struct->size)
			printf_struct->res[0] = '+';
		else if (printf_struct->res_len >= printf_struct->size)
			printf_struct->res = put_char_first(printf_struct->res, '+');
	}
	else
	{
		i = where_start(printf_struct);
		if (i > 0)
			printf_struct->res[--i] = '+';
		else if (i == 0)
			printf_struct->res = put_char_first(printf_struct->res, '+');
	}
}

void 	plus_handler(t_printf *printf_struct)
{
	if (printf_struct->accuracy && printf_struct->size)
	{
		if (printf_struct->size > printf_struct->accuracy)
		{
			if (printf_struct->res_len < printf_struct->accuracy)
				printf_struct->res[printf_struct->size - printf_struct->accuracy - 1] = '+';
			else if ((printf_struct->conversion == 'f' || printf_struct->conversion == 'F') &&
					 printf_struct->size > printf_struct->res_len)
				printf_struct->res[printf_struct->size - printf_struct->res_len -
								   printf_struct->is_point] = '+';
			else if (printf_struct->res_len >= printf_struct->accuracy)
				printf_struct->res = put_char_first(printf_struct->res, '+');
		}
		else if (printf_struct->size <= printf_struct->accuracy)
			printf_struct->res = put_char_first(printf_struct->res, '+');
	}
	else if (printf_struct->size)
		plus_handler25(printf_struct);
	else if (printf_struct->accuracy)
		printf_struct->res = put_char_first(printf_struct->res, '+');
	else if (!printf_struct->accuracy || !printf_struct->size)
		printf_struct->res = put_char_first(printf_struct->res, '+');
}

void 	zero_handler(t_printf *printf_struct)
{
	int i;

	i = -1;
	while (printf_struct->res[++i])
	{
		if (printf_struct->res[i] == ' ')
			printf_struct->res[i] = '0';
	}
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
	if (printf_struct->accuracy && printf_struct->size)
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
	else if (!printf_struct->accuracy || !printf_struct->size)
		printf_struct->res = put_char_first(printf_struct->res, ' ');
}

void 	negnb_handler(t_printf *printf_struct)
{
	int	i;

	i = 0;
	while (printf_struct->res[i] == ' ')
		i++;
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

void 	minus_handler(t_printf *ps)
{
	int		i;
	int		j;
	char 	*res;

	i = 0;
	j = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(ps->res) + 1))))
		return ;
	if (ps->conversion == 's')
	{
		while ((unsigned long)i < ft_strlen(ps->res) - (ps->is_space + ps->res_len))
			i++;
	}
	else
	{
		while (i < (int)ft_strlen(ps->res) - ((ps->is_space || ps->is_plus) + (ps->res_len +
		ps->is_nan + ps->is_inf < ps->accuracy ? ps->accuracy : ps->res_len)) && ps->res[i] == ' ')
			i++;
	}
	while (ps->res[i])
		res[j++] = ps->res[i++];
	while (i > j)
		res[j++] = ' ';
	res[j] = '\0';
	ps->res = res;
	free(res);
}

void 	inf_case_handler(t_printf *ps)
{
	int	i;

	i = 0;
	while (ps->res[i] == ' ')
		i++;
	if (--i >= 0)
		ps->res[i] = ps->is_plus? '+' : ' ';
	else
		ps->res = put_char_first(ps->res, ps->is_plus? '+' : ' ');
}

void 	flags_handler(const char *str, t_printf *ps)
{
	if (!ps->is_nan && !ps->is_inf)
	{
		if (ps->is_zero)
			zero_handler(ps);
		if (ps->is_plus && !ps->is_nan)
			plus_handler(ps);
		if (ps->is_space && !ps->is_nan)
			space_handler(ps);
		if ((ps->conversion == 'x' || ps->conversion == 'X' || ps->conversion == 'p') &&
		ps->is_hash)// && ps->zero_arg) && !(ps->conversion == 'x' || ps->conversion == 'X'))
			hash_hex_handler(ps);
		if (ps->conversion == 'o' && !ps->accuracy && ps->is_hash)
			hash_oct_handler((char*)str, ps);
		if (ps->is_neg)
			negnb_handler(ps);
		if ((ps->conversion == 'f' || ps->conversion == 'F') && ps->is_hash)
			hash_float_handler((char*)str, ps);
	}
	if (ps->is_inf && (ps->is_plus || ps->is_space))
		inf_case_handler(ps);
	if (ps->is_minus)
		minus_handler(ps);
}

void    init_t_printf2(t_printf *printf_struct)
{
	printf_struct->conversion = 0;
	printf_struct->res_len = 0;
	printf_struct->is_neg = 0;
	printf_struct->is_l = 0;
	printf_struct->is_ll = 0;
	printf_struct->is_h = 0;
	printf_struct->is_hh = 0;
	printf_struct->is_hash = 0;
	printf_struct->is_zero = 0;
	printf_struct->is_minus = 0;
	printf_struct->is_plus = 0;
	printf_struct->is_space = 0;
	printf_struct->accuracy = 0;
	printf_struct->is_point = 0;
	printf_struct->error_conv = -42;
	printf_struct->zero_arg = 0;
	printf_struct->is_nan = 0;
	printf_struct->is_inf = 0;
}

void	init_t_printf1(t_printf *printf_struct)
{
	printf_struct->res = NULL;
	printf_struct->ret_value = 0;
	printf_struct->size = 0;
	init_t_printf2(printf_struct);
}

void init(t_printf *printf_struct, t_int *int_struct)
{
	init_t_printf1(printf_struct);
	init_t_int(int_struct);
}

int is_conversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
	{
		return (1);
	}
	return (0);
}
int is_digit(char c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}
int second_percent(const char *str)
{
	int i;

	i = 0;
	if(str[0] == '%')
		return (2);
	if(is_digit(str[0]) || str[0] == '-' || str[0] == '+')
	{
		if (!is_digit(str[0]))
			i++;
		while ((!is_conversion(str[i]) && is_digit(str[i])) || str[i] == '%')
		{
			if (str[i] == '%')
				return (i + 2);
			i++;
		}
	}
	return(0);
}

void	fix_flag_errors(t_printf *ps)
{
	if (ps->is_nan)
	{
		ps->is_plus = 0;
		ps->is_space = 0;
	}
	if (ps->is_plus && ps->conversion == 'u')
		ps->is_plus = 0;
	if (ps->is_space && ps->conversion == 'u')
		ps->is_space = 0;
	if (ps->zero_arg && ps->conversion != 'f' && ps->conversion != 'F')
		ps->is_hash = 0;
	if (ps->conversion == 'x' || ps->conversion == 'X' || ps->conversion == 'p' ||
	ps->conversion == 'o' || ps->conversion == 's' || ps->conversion == 'c')
	{
		ps->is_plus = 0;
		ps->is_space = 0;
	}
	if (ps->is_space && (ps->conversion == 'f' || ps->conversion == 'F'))
		ps->is_zero = 0;
	if ((ps->accuracy || ps->is_minus) && ps->conversion != 'f' && ps->conversion != 'F')
		ps->is_zero = 0;
	if (ps->is_plus)
		ps->is_space = 0;
	if (ps->conversion == 'c' || ps ->conversion == '%')
	{
		ps->accuracy = 0;
		ps->is_space = 0;
		ps->is_plus = 0;
	}
	if (ps->conversion == 'p')
		ps->is_hash = 1;
}

/*int 	parse(const char *input_str, va_list ap, t_printf *printf_struct, int i)
{
	i = parse_flags(input_str, i, printf_struct);
	conv_handler(ap, printf_struct);
	fix_flag_errors(printf_struct);
	accuracy_and_size_handler(printf_struct);
	flags_handler(input_str, printf_struct);
	printf_struct->ret_value += ft_putstr(printf_struct->res);
	if (printf_struct->conversion == 'c' && printf_struct->zero_arg)
		ft_putchar('\0');
	init_t_printf2(printf_struct);
	return (input_str[i] == '\0' ? i : i + 1);
}*/

int		ft_printf(const char *input_str, ...)
{
	va_list		ap;
	t_printf	printf_struct;
	t_int       int_struct;
	int		i;
	//int     pos_percent;

	i = 0;
	init(&printf_struct, &int_struct);
	va_start(ap, input_str);
	while (input_str[i])
	{
		while (input_str[i] && input_str[i] != '%')
			printf_struct.ret_value += ft_putchar(input_str[i++]);
		/*pos_percent = second_percent(&input_str[i + 1]);
		if(pos_percent && input_str[i] == '%')
		{
			write(1, "%", 1);
			i += pos_percent;
		}*/
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
