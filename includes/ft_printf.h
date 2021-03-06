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
	char 		*res;
	int         isneg;
	int			iszero;
	int 		is_l;
	int 		is_ll;
	int 		is_h;
	int 		is_hh;
	int 		is_L;
}				t_printf;

typedef struct s_int
{
    long long   longlongnb;
    long        longnb;
    int         intnb;
    short       shortnb;
}               t_int;

void	init(t_printf *printf_struct, t_int *int_struct);
void    init_t_int(t_int *int_struct);
int 	parse(va_list ap, int i, t_printf *printf_struct);
char	*ft_itoa_printf1(long long value, int base, t_printf *printf_struct);
char	*ft_itoa_printf_u1(unsigned long long value, int base, t_printf *printf_struct);

#endif //FT_PRINTF_FT_PRINTF_H
