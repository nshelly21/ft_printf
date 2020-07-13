//
// Created by Denisse Gruyere on 7/13/20.
//

#include "includes/ft_printf.h"

int main(void)
{
	char *nickname1;
	char *nickname2;

	nickname1 = "nshelly";
	nickname2 = "dgruyere";

	/*ft_printf("hello my nickname is %s %s %s", nickname1, nickname2, nickname1);
	ft_printf("hello! The bomb is ticking down, %s: %d, %d, %d", nickname2, 3, 2, 1);
	ft_printf("%s, %d in octal form is %o, in hexadecimal %x", nickname1, 100, 100, 100);*/
	ft_printf("hello my another nickname is %-20s .", "10");
	//TODO check hh h ll l with printf tests

	return 0;
}