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

char *conv_string(va_list ap, t_printf *printf_struct)
{
	char *identified_string;
	char *res;

	identified_string = va_arg(ap, typeof(identified_string));
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(identified_string) + 1))))
		return (0);
	res = ft_strcpy(res, identified_string);
	return (res);
}

int parse(const char *str, va_list ap, int i, t_printf *printf_struct)
{
	char	*res;

	res = NULL;
	if (printf_struct->conversion == 's')
		conv_string(ap, printf_struct);
	ft_putstr(res);
	return (i);
}

size_t ft_printf(const char *input_str, ...)
{
	va_list		ap;
	size_t		res;
	t_printf	printf_struct;
	char	*identified_string;
	char	*text;
	int		i;

	i = 0;
	res = 0;
	init(&printf_struct);
	va_start(ap, input_str);
	//identified_string = va_arg(ap, typeof(identified_string));
	//text = reader_identifier(input_str);
	//print_string(text);
	while (input_str[i])
	{
		if (input_str[i] != '%')
			res += write(1, input_str[i++], 1);
		else if (input_str[i])
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
	write(1, "\n", 1);
	return (res);
}

void init(t_printf *printf_struct)
{
	printf_struct->conversion = 0;
}

int main(void)
{
	char *nickname1;
	char *nickname2;

	nickname1 = "nshelly";
	nickname2 = "dgruyere";

	ft_printf("hello my nickname is %s", nickname1 );
	ft_printf("hello my another nickname is %s", nickname2);
	ft_printf("hello my another nickname is %s", nickname1, nickname2);

	return 0;
}
