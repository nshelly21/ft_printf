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
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 16, printf_struct));
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
		return(ft_itoa_printf_u1((unsigned long long)int_struct.intnb, 16, printf_struct));
	}
	if (printf_struct->is_l)
	{
		int_struct.intnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longnb, 16, printf_struct));
	}
	if (printf_struct->is_ll)
	{
		int_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longlongnb, 16, printf_struct));
	}
	if (printf_struct->is_h)
	{
		int_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 16, printf_struct));
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
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 10, printf_struct));
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
		return(ft_itoa_printf_u1((unsigned long long)int_struct.intnb, 10, printf_struct));
	}
	if (printf_struct->is_l)
	{
		int_struct.intnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longnb, 10, printf_struct));
	}
	if (printf_struct->is_ll)
	{
		int_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longlongnb, 10, printf_struct));
	}
	if (printf_struct->is_h)
	{
		int_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 10, printf_struct));
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
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 8, printf_struct));
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
		return(ft_itoa_printf_u1((unsigned long long)int_struct.intnb, 8, printf_struct));
	}
	if (printf_struct->is_l)
	{
		int_struct.intnb = (unsigned long)va_arg(ap, long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.longnb, 8, printf_struct));
	}
	if (printf_struct->is_ll)
	{
		int_struct.longlongnb = (unsigned long long)va_arg(ap, long long);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 8, printf_struct));
	}
	if (printf_struct->is_h)
	{
		int_struct.shortnb = (unsigned short)va_arg(ap, int);
		return(ft_itoa_printf_u1((unsigned long long)int_struct.shortnb, 8, printf_struct));
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
			return(ft_itoa_printf_u1((unsigned long long)int_struct.longlongnb, 10, printf_struct));
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

char	*ft_charcpy(char *dest, const char src)
{
	dest[0] = src;
	dest[1] = '\0';
	return (dest);
}

char    *conv_char(va_list ap)//, t_printf *printf_struct)
{
	char identified_string;
	char *res;

	identified_string = va_arg(ap, int);
	if (!(res = (char*)malloc(sizeof(char) * 1)))
		return (0); //TODO write proper exit_error function
	res = ft_charcpy(res, (char)identified_string);
	return (res);
}

char    *conv_pointer(va_list ap)//, t_printf *printf_struct)
{
	char identified_string;
	char *res;

	identified_string = va_arg(ap, int);
	if (!(res = (char*)malloc(sizeof(char) * 1)))
		exit(0); //TODO write proper exit_error function
	res = ft_charcpy(res, (char)identified_string);
	return (res);
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

void 	conv_float(va_list ap, t_printf *printf_struct)
{
	long double	nb;

	nb = (long double)va_arg(ap, double);
	if (!(printf_struct->accuracy) && !(printf_struct->is_point))
		printf_struct->accuracy = 6;
	if (nb < 0)
	{
		printf_struct->is_neg = 1;
		nb = nb * (-1);
	}
	float_handler(nb, printf_struct);
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
		printf_struct->res = conv_string(ap);
	else if (printf_struct->conversion == 'c')
		printf_struct->res = conv_char(ap);
	else if (printf_struct->conversion == 'p')
		printf_struct->res = conv_pointer(ap);
	else if (printf_struct->conversion == 'd' || printf_struct->conversion == 'i')
        printf_struct->res = conv_int(ap, printf_struct);
    else if (printf_struct->conversion == 'o')
		printf_struct->res = conv_oct(ap, printf_struct);
    else if (printf_struct->conversion == 'u')
        printf_struct->res = conv_unsint(ap, printf_struct);
    else if (printf_struct->conversion == 'x' || printf_struct->conversion == 'X')
		printf_struct->res = conv_hex(ap, printf_struct);
    else if (printf_struct->conversion == 'f' || printf_struct->conversion == 'F')
        conv_float(ap, printf_struct);
    else if (printf_struct->conversion == '%')
        conv_percent(printf_struct);
	else if (printf_struct->res)
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
			i = i + init_accuracy(input_str, i, printf_struct); //NOTE when is_point it is the accuracy
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

	tmp = NULL;
	i = 0;
	len = 0;
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
		if (printf_struct->accuracy > printf_struct->size)
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
		while (i < (int)ft_strlen(ps->res) - ((ps->is_space || ps->is_plus) +
		(ps->res_len < ps->accuracy ? ps->accuracy : ps->res_len)) && ps->res[i] == ' ')
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

void 	flags_handler(const char *str, t_printf *printf_struct)
{
	if (printf_struct->is_zero)
		zero_handler(printf_struct);
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
	printf_struct->zero_arg = 0;
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

int		ft_printf(const char *input_str, ...)
{
	va_list		ap;
	int		res;
	t_printf	printf_struct;
	t_int       int_struct;
	int		i;
	int     pos_percent;

	i = 0;
	res = 0;
	init(&printf_struct, &int_struct);
	va_start(ap, input_str);
	while (input_str[i])
	{
		while (input_str[i] && input_str[i] != '%')
		{
			res += ft_putchar(input_str[i++]);
		}
		pos_percent = second_percent(&input_str[i+1]);
		if(pos_percent && input_str[i] == '%')
		{
			write(1, "%", 1);
			i += pos_percent;
		}
		else if (input_str[i])
		{
			i = parse_flags(input_str, ++i, &printf_struct);
			conv_handler(ap, &printf_struct);
			accuracy_and_size_handler(&printf_struct);
			flags_handler(input_str, &printf_struct);
			ft_putstr(printf_struct.res);
			init_t_printf(&printf_struct);
			i++;
		}
	}
	va_end(ap);
	return (res); //TODO return -1 if FATAL ERROR
}
