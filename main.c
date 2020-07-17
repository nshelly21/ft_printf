//
// Created by Denisse Gruyere on 7/13/20.
//

#include "../includes/ft_printf.h"

int main(void)
{
	char *nickname1;
	char *nickname2;

	nickname1 = "nshelly";
	nickname2 = "dgruyere";


	/*ft_printf("hello my nickname is %s %s %s\n", nickname1, nickname2, nickname1);
	ft_printf("hello! The bomb is ticking down, %s: %d, %d, %d\n", nickname2, 3, 2, 1);
	ft_printf("%s, %d in octal form is %o, in hexadecimal %x\n", nickname1, 100, 100, 100);
	ft_printf("hello my another nickname is %-20s .\n", "10");*/

	//simple TESTS FROM https://alvinalexander.com/programming/printf-format-cheat-sheet/
	//integer formatting

	/*ft_printf("hello%#o\n", 10);
	ft_printf("hello %#lx\n", "hello");
	printf("hello %p\n", "hello");
	printf("hello %#lx\n", "hello");
	printf("hello %#o\n", 10);
	ft_printf("hola%c\n", 'd');
	printf("hola%c\n", 'd');
	ft_printf("%-5d\n", 10);							//'10   '
	ft_printf("%05d\n", 10);							//'00010'
	ft_printf("%+5d\n", 10);							//'  +10'
	ft_printf("%-+5d\n", 10);							//'+10  '
	//integer zero-fill option
	ft_printf("%03d\n", 0);								//000
	ft_printf("%03d\n", 1);								//001
	ft_printf("%03d\n", 123456789);						//123456789
	ft_printf("%03d\n", -10);								//-10
	ft_printf("%03d\n", -123456789);						//-123456789
	//Left-justifying printf integer output
	ft_printf("%-3d\n", 0);								//0
	ft_printf("%-3d\n", 123456789);						//123456789
	ft_printf("%-3d\n", -10);								//-10
	ft_printf("%-3d\n", -123456789);						//-123456789
	//Controlling integer width with printf
	ft_printf("%3d\n", 0);								//0
	ft_printf("%3d\n", 123456789);						//123456789
	ft_printf("%3d\n", -10);								//-10
	ft_printf("%3d\n", -123456789);						//-123456789
	//formatting floating point numbers
	ft_printf("%.1f\n", 10.3456);						//'10.3'
	ft_printf("%.2f\n", 10.3456);						//'10.35'
	ft_printf("%8.2f\n", 10.3456);						//'   10.35'
	ft_printf("%8.4f\n", 10.3456);						//' 10.3456'
	ft_printf("%08.2f\n", 10.3456);						//'00010.35'
	ft_printf("%-8.2f\n", 10.3456);						//'10.35   '
	ft_printf("%-8.2f\n", 101234567.3456);				//'101234567.35'
	//string
	ft_printf("%s\n", "Hello");							//'Hello'
	ft_printf("%10s\n", "Hello");						//'     Hello'
	ft_printf("%-10s\n", "Hello");						//'Hello     '
	ft_printf("%s\n", nickname1);
	ft_printf("%10s\n", nickname2);
	ft_printf("%-10s\n", nickname1);*/
	//TODO check hh h ll l with printf tests

	long long int llmax = 9223372036854775807;
	//ft_printf("%%");
	//ft_printf("this % i number", 17);
	ft_printf("%.03s", "hi men");
	ft_printf("\n");
	/*ft_putchar('\n');
	printf("%%");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_printf("%5%");
	ft_putchar('\n');
	printf("%5%");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_printf("%-5%");
	ft_putchar('\n');
	printf("%-5%");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_printf("%05");
	ft_putchar('\n');
	printf("%05%");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_printf("%-05s");
	ft_putchar('\n');
	printf("%-05s%");
	/*
	Test  12 (nocrash_nullspec_5w) : FAILED.
			(nocrash test: automatically passes provided no unexpected failure)
	First line of code: {return test("%5");}
	SEGFAULT
	Test  13 (nocrash_nullspec_5wzp) : FAILED.
			(nocrash test: automatically passes provided no unexpected failure)
	First line of code: {return test("%05");}
	SEGFAULT
	Test  14 (nocrash_nullspec_5wzplj) : FAILED.
			(nocrash test: automatically passes provided no unexpected failure)
	First line of code: {return test("%-05");}
	SEGFAULT
	Test  15 (nocrash_nullspec_5wlj) : FAILED.
			(nocrash test: automatically passes provided no unexpected failure)
	First line of code: {return test("%-5");}
	SEGFAULT
	Test  77 (s_prec_03_no_width_s_hidden) : FAILED.
			First line of code: {return test("%.03s", s_hidden);}
	expected output : "hi "
	your output     : "3s"
	expected (nonprintable as hex) : "hi "
	actual   (nonprintable as hex) : "3s"*/

	return 0;
}
