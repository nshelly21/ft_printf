#include <stdio.h>
#include <unistd.h>// for write function
#include <stdlib.h> //for malloc, free and exit functions
#include <stdarg.h>
#include <string.h>//prohibited but im not going to rewrite stycpy and strchr

/* print all non-negative args one at a time;
   all args are assumed to be of int type */

size_t ft_strlen(const char *string)
{
	size_t i;

	i = 0;
	while(string[i] != '\0')
		i++;
	return (i);
}

void print_string(char *string)
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
}

void ft_printf(const char *format, ...)
{
	va_list ap;
	char *identified_string;
	char *text;
	int i;

	i = 0;
	va_start(ap, format);
	identified_string = va_arg(ap, typeof(identified_string));
	text = reader_identifier(format);
	print_string(text);
	while (format[i] != '\0') {
		if (format[i] == '%' && format[i + 1] == 's')//check if the parameter is string, so print as string
		{
			print_string(identified_string);
		}
		i++;
	}

	va_end(ap);
	write(1, "\n", 1);
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
