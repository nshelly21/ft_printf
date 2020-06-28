//
// Created by Student on 6/26/20.
//

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>// for write function
# include <stdlib.h> //for malloc, free and exit functions
# include <stdarg.h>

typedef struct	s_printf
{
	char 		conversion;
	char 		res;
}				t_printf;

void	init(t_printf *printf_struct);
int 	parse(const char *str, va_list ap, int i, t_printf *printf_struct);

#endif //FT_PRINTF_FT_PRINTF_H
