//
// Created by Student on 6/26/20.
//

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>// for write function
# include <stdlib.h> //for malloc, free and exit functions
# include <stdarg.h>
# include <string.h>//prohibited but im not going to rewrite stycpy and strchr

typedef struct	s_printf
{
	char 		conversion;
	char 		*res;
	int 		res_len;
	int         is_neg;
	int 		is_l;
	int 		is_ll;
	int 		is_h;
	int 		is_hh;
	int 		is_hash;
	int 		is_zero;
	int 		is_minus;
	int 		is_plus;
	int 		is_space;
	int 		accuracy;
	int 		size;
	int 		is_point;
	int 		error_conv;
	int 		zero_arg;
	int			ret_value;
	int 		is_nan;
	int 		is_inf;
}				t_printf;

typedef struct s_int
{
    long long   longlongnb;
    long        longnb;
    int         intnb;
    short       shortnb;
}               t_int;

int		ft_printf(const char *input_str, ...);
void	init(t_printf *printf_struct, t_int *int_struct);
void    init_t_int(t_int *int_struct);
void 	conv_handler(va_list ap, t_printf *printf_struct);
char	*ft_itoa_printf1(long long value, int base, t_printf *printf_struct);
char	*ft_itoa_printf_u1(unsigned long long value, int base, t_printf *printf_struct);
int 	where_start(t_printf *printf_struct);

#endif //FT_PRINTF_FT_PRINTF_H
