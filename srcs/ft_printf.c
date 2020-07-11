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
    char    *res;
    t_int   int_struct;

	init_t_int(&int_struct);
	res = NULL;
	if (printf_struct->is_l == 0 && printf_struct->is_ll && printf_struct->is_h && printf_struct->is_hh)
	{
		int_struct.intnb = va_arg(ap, int);
		return(ft_itoa_printf1((long long) int_struct.intnb, 10, printf_struct));
	}
	if (printf_struct->is_l == 1 || printf_struct->is_ll == 1)
	{
		int_struct.longlongnb = va_arg(ap, long long);
		if (int_struct.longlongnb < 0)
			printf_struct->isneg = 1;
		if (int_struct.longlongnb < -9223372036854775807 || int_struct.longlongnb > 9223372036854775807)
			return(ft_itoa_printf_u1((unsigned long long)int_struct.longlongnb, 10, printf_struct));
		else
			return(ft_itoa_printf1(int_struct.longlongnb, 10, printf_struct));
	}
    return(conv_int25(ap, printf_struct));
}
//TODO
char    *conv_string(va_list ap, t_printf *printf_struct)
{
	char *identified_string;
	char *res;

	identified_string = va_arg(ap, typeof(identified_string));
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(identified_string) + 1))))
		return (0); //TODO write proper exit_error function
	res = ft_strcpy(res, identified_string);
	return (res);
}

int     parse(const char *str, va_list ap, int i, t_printf *printf_struct)
{
	if (printf_struct->conversion == 's')
		printf_struct->res = conv_string(ap, printf_struct);
	/*TODO else if (printf_struct->conversion == 'c')
		printf_struct->res = conv_char(ap, printf_struct);*/
	else if (printf_struct->conversion == 'd' || printf_struct->conversion == 'i')
        printf_struct->res = conv_int(ap, printf_struct);
    else if (printf_struct->conversion == 'o')
        printf_struct->res = conv_oct(ap, printf_struct);
    else if (printf_struct->conversion == 'u')
        printf_struct->res = conv_unsint(ap, printf_struct);
    else if (printf_struct->conversion == 'x' || printf_struct->conversion == 'X')
        printf_struct->res = conv_hex(ap, printf_struct);
    else if (printf_struct->conversion == 'f' || printf_struct->conversion == 'F')
        i = i + 0;
        //TODO printf_struct->res = conv_?(ap, printf_struct);
    else if (printf_struct->conversion == '%')
        i = i + 0;
        //TODO printf_struct->res = conv_?(ap, printf_struct);
	ft_putstr(printf_struct->res);
	return (i + 2);
}

int ft_printf(const char *input_str, ...)
{
	va_list		ap;
	int		res;
	t_printf	printf_struct;
	t_int       int_struct;
	char	*identified_string;
	char	*text;
	int		i;

	i = 0;
	res = 0;
	init(&printf_struct, &int_struct);
	va_start(ap, input_str);
	//identified_string = va_arg(ap, typeof(identified_string));
	//text = reader_identifier(input_str);
	//print_string(text);
	while (input_str[i])
	{
		while (input_str[i] && input_str[i] != '%')
			res += ft_putchar(input_str[i++]);
		if (input_str[i])
		{
			printf_struct.conversion = input_str[i + 1];
			i = parse(input_str, ap, i, &printf_struct);
		}
		/*if (input_str[i] == '%' && input_str[i + 1] == 's')//check if the parameter is string, so print as string
		{
			print_string(identified_string);
		}*/
	}
	va_end(ap);
	write(1, "\n", 1); //TODO DELETE if not necessary
	return (res); //TODO return -1 if FATAL ERROR
}

void    init_t_printf(t_printf *printf_struct)
{
    printf_struct->conversion = 0;
    printf_struct->res = NULL;
    printf_struct->isneg = 0;
    printf_struct->iszero = 0;
	printf_struct->is_l = 0;
	printf_struct->is_ll = 0;
	printf_struct->is_h = 0;
	printf_struct->is_hh = 0;
	printf_struct->is_L = 0;
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

int main(void)
{
	char *nickname1;
	char *nickname2;

	nickname1 = "nshelly";
	nickname2 = "dgruyere";

	ft_printf("hello my nickname is %s %s %s", nickname1, nickname2, nickname1);
	ft_printf("hello! The bomb is ticking down, %s: %d, %d, %d", nickname2, 3, 2, 1);
	ft_printf("%s, %d in octal form is %o, in hexadecimal %x", nickname1, 100, 100, 100);
	//TODO check hh h ll l with printf tests

	return 0;
}
