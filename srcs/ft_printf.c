#include "includes/ft_printf.h"
#include <stdio.h>

/*char *conv_string(va_list ap, t_printf *printf_struct)
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
	if (printf_struct->conversion == 's')
		printf_struct->res = conv_string(ap, printf_struct);
	//else if ()
	ft_putstr(printf_struct->res);
	return (i + 2);
}

int ft_printf(const char *input_str, ...)
{
	va_list		ap;
	int		res;
	t_printf	printf_struct;
	//char	*identified_string;
	//char	*text;
	int		i;

	i = 0;
	res = 0;
	init(&printf_struct);
	va_start(ap, input_str);

	while (input_str[i])
	{
		while (input_str[i] != '%')
			res += ft_putchar(input_str[i++]);
		if (input_str[i])
		{
			printf_struct.conversion = input_str[i + 1];
			i = parse(input_str, ap, i, &printf_struct);
		}
	}
	va_end(ap);
	write(1, "\n", 1);
	return (res);
}*/

void init(t_printf *printf_struct)
{
	printf_struct->conversion = 0;
	printf_struct->res = NULL;
}

size_t  count_flags(const char *string)
{
	size_t i;
	size_t  j;

	i = 0;
	j = 0;
	while(i < ft_strlen(string))
	{
		if(string[i] == '%' && string[i + 1] == '%')
			i = i + 2;
		if(string[i] == '%' && string[i + 1] != '%')
			j++;
		i++;
	}
	return (j);
}

char* return_flags(const char *string)
{
	size_t i;
	int j;
	char* flags;
	size_t  number_of_flags;

	i = 0;
	j = 0;
	number_of_flags = count_flags(string);
	flags = (char*)malloc(sizeof(char)*number_of_flags);
	while(i < ft_strlen(string))
	{
		if(string[i] == '%' && string[i + 1] == '%')
			i = i + 1;
		else if (string[i] == '%' && string[i + 1] != '%')
		{
			flags[j] = string[i + 1];
			j++;
		}
		i++;
	}
	flags[j] = '\0';
	return (flags);
}

void print_elements_list(t_list *elem)
{
	write(1, elem->content, ft_strlen(elem->content));
}

int ft_printf(const char *input_string, ...)
{
	va_list		ap;
	va_start(ap, input_string);
	char* word;
	char* flags;
	t_list* words_list;
	int i;

	i = 0;
	flags = return_flags(input_string);

	while (flags[i] != '\0')
	{
		if (flags[i] == 'd')
			word = ft_itoa(va_arg(ap, int));
		else if  (flags[i] == 's')
			word =  va_arg(ap, char*);
		else if (flags[i] == 'i')
			word = "не обработанно";
		else if  (flags[i] == 'u')
			word = "не обработанно";
		else if  (flags[i] == 'x')
			word = "не обработанно";
		else if  (flags[i] == 'p')
			word =  "не обработанно";
		if  (i == 0)
			words_list = ft_lstnew(word, ft_strlen(word));
		if (i!= 0)
			ft_lstadd(&words_list, ft_lstnew(word, ft_strlen(word)));
		write(1, word, ft_strlen(word));
		i++;
	}
	char* text = {"\nЕсли печатать связанный список где хронил все слова\n"};
	write(1, text, ft_strlen(text));
	ft_lstiter(words_list, print_elements_list);
	ft_putchar('\n');
	return (1);
}


int main(void)
{
	char *nickname1;
	char *nickname2;

	nickname1 = "nshelly";
	nickname2 = "dgruyere";

	printf("У нас есть:\n");
	ft_printf("hello my another nickname is %s and %s and we are %d\n", nickname1, nickname2, 2);
	printf("А должен быть:\n");
	printf("hello my another nickname is %s and %s and we are %d\n", nickname1, nickname2, 2);


	return 0;
}
