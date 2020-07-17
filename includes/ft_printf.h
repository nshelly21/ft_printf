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

typedef struct	s_unsint
{
	unsigned long long   longlongnb;
	unsigned long        longnb;
	unsigned int         intnb;
	unsigned short       shortnb;
}				t_unsint;

int		ft_printf(const char *input_str, ...);
void 	conv_handler(va_list ap, t_printf *printf_struct);

/*
*---------------------ft_itoa.c-------------------------
 * static char	*ft_itoa_printf2(long long value, int base, char *str)
 * static char	*ft_itoa_printf_u2(unsigned long long value, int base, char *str)
*/

char	*ft_itoa_printf1(long long value, int base, t_printf *printf_struct);
char	*ft_itoa_printf_u1(unsigned long long value, int base, t_printf *printf_struct);
int 	where_start(t_printf *printf_struct);

/*
*---------------------init.c-------------------------
 * */
void	init_t_printf1(t_printf *printf_struct);
void    init_t_printf2(t_printf *printf_struct);
void    init(t_printf *printf_struct, t_int *int_struct);
int 	init_flags(const char *str, int i, t_printf *printf_struct);
void    init_t_int(t_int *int_struct);

/*
*---------------------init_length_accuracy.c-------------------------
 */
void    init_t_unsint(t_unsint *unsint_struct);
int		init_accuracy(const char *input_str, int i, t_printf *printf_struct);
int		init_length(const char *input_str, int i, t_printf *printf_struct);

/*
*---------------------conversions_string_char.c-------------------------
 */
char    *conv_string(va_list ap, t_printf *printf_struct);
char    *conv_char(va_list ap, t_printf *printf_struct);

/*
*---------------------space_handler.c-------------------------
 */
void 	space_handler25(t_printf *printf_struct);
void 	space_handler(t_printf *printf_struct);

/*
*---------------------conv_usint_hex.c-------------------------
*/
char 	*conv_hex25(va_list ap, t_printf *printf_struct, t_unsint unsint_struct);
char 	*conv_hex(va_list ap, t_printf *printf_struct);

/*
*---------------------conv_usint.c-------------------------
*/
char	*conv_unsint25(va_list ap, t_printf *printf_struct, t_unsint int_struct);
char 	*conv_unsint(va_list ap, t_printf *printf_struct);

/*
*---------------------conv_int_oct.c-------------------------
*/
char	*conv_oct25(va_list ap, t_printf *printf_struct, t_unsint unsint_struct);
char	*conv_oct(va_list ap, t_printf *printf_struct);
char	*conv_int25(va_list ap, t_printf *printf_struct);
char    *conv_int(va_list ap, t_printf *printf_struct);

/*
*---------------------checks.c-------------------------
*/
int 	is_flag(const char *str, int i);
int 	is_conv(const char *str, int i);
int 	is_length(const char *str, int i);

/*
*---------------------round.c-------------------------
*/
void 	round1(t_printf *printf_struct);
void 	round2(t_printf *printf_struct);

/*
*---------------------conv_handler.c-------------------------
*/
void     conv_handler(va_list ap, t_printf *printf_struct);

/*
*---------------------handler_float_hex_oct.c-------------------------
*/
void 	hash_float_handler(char *str, t_printf *printf_struct);
void	float_handler(long double nb, t_printf *printf_struct);
void 	hash_oct_handler(char *str, t_printf *printf_struct);
void	hash_hex_handler25(char *hex, int j, t_printf *printf_struct);
void 	hash_hex_handler(t_printf *printf_struct);

/*
*---------------------handler_accuraycy_size.c-------------------------
*/
void 	accuracy_handler(t_printf *printf_struct);
void 	size_handler(t_printf *printf_struct);
void	accuracy_and_size_handler(t_printf *printf_struct);

/*
*---------------------fix.c-------------------------
*/
void	fix_flag_errors(t_printf *ps);

/*
*---------------------handler_plus_zero_minus.c-------------------------
*/

void 	plus_handler25(t_printf *printf_struct);
void 	plus_handler(t_printf *printf_struct);
void 	zero_handler(t_printf *printf_struct);
void 	minus_handler(t_printf *ps);

/*
*---------------------conv_pointer_float_percent.c-------------------------
*/
void    conv_pointer(va_list ap, t_printf *printf_struct);
void 	conv_percent( t_printf *printf_struct);
void 	conv_float(va_list ap, t_printf *ps);

/*
*---------------------handler_parse_flags.c-------------------------
*/
void 	flags_handler(const char *str, t_printf *ps);
int		parse_flags(const char *input_str, int i, t_printf *printf_struct);

/*
*---------------------handler_infcase_negnb.c-------------------------
*/
void 	negnb_handler(t_printf *printf_struct);
void 	inf_case_handler(t_printf *ps);
int 	count_dig(int nb);

/*
*---------------------put_char_firt.c-------------------------
*/
char 	*put_char_first(char *str, char c);

/*
*---------------------capitalize.c-------------------------
*/
char	*capitalize(char *str);

#endif //FT_PRINTF_FT_PRINTF_H
