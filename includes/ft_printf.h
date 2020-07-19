//
// Created by Student on 6/26/20.
//

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>// for write function
# include <stdlib.h> //for malloc, free and exit functions
# include <stdarg.h>
# include <string.h>//prohibited but im not going to rewrite stycpy and strchr

typedef struct	s_printf
{
	char 		conv;
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
	int 		error;
	int 		min_zero;
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
char	*conv_handler(va_list ap, t_printf *printf_struct);

/*
*---------------------ft_itoa.c-------------------------
 * static char	*ft_itoa_printf2(long long value, int base, char *str)
 * static char	*ft_itoa_printf_u2(unsigned long long value, int base, char *str)
*/

char	*ft_itoa_printf1(long long value, int base, t_printf *printf_struct);
char	*ft_itoa_printf_u1(unsigned long long value, int base, t_printf *ps);
int 	where_start(char *str, t_printf *printf_struct);

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
int		init_length(const char *input_str, int i, t_printf *ps);

/*
*---------------------conversions_string_char.c-------------------------
 */
char    *conv_string(va_list ap, t_printf *ps);
char    *conv_char(va_list ap, t_printf *ps);

/*
*---------------------space_handler.c-------------------------
 */
char	*space_handler25(char *str, t_printf *printf_struct);
char	*space_handler(char *str, t_printf *ps);

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
char	*round1(t_printf *ps, char *res);
char	*round2(t_printf *printf_struct, char *res);

/*
*---------------------conv_handler.c-------------------------
*/
char	*conv_handler(va_list ap, t_printf *printf_struct);

/*
*---------------------handler_float_hex_oct.c-------------------------
*/
char	*hash_float_handler(char *str);
char	*float_handler(long double nb, t_printf *ps, char *res);
char	*hash_oct_handler(char *str);
char	*hash_hex_handler(char *str, t_printf *ps);

/*
*---------------------handler_accuraycy_size.c-------------------------
*/
char	*accuracy_handler(char *res, t_printf *printf_struct);
char	*size_handler(char *res, t_printf *printf_struct);
char	*accuracy_and_size_handler(char *res, t_printf *ps);

/*
*---------------------fix.c-------------------------
*/
void	fix_flag_errors1(t_printf *ps);

/*
*---------------------handler_plus_zero_minus.c-------------------------
*/

char	*plus_handler25(char *res, t_printf *printf_struct);
char	*plus_handler(char *res, t_printf *ps);
char	*zero_handler(char *res);
char	*minus_handler(char *res, t_printf *ps);

/*
*---------------------conv_pointer_float_percent.c-------------------------
*/
char	*conv_pointer(va_list ap, t_printf *printf_struct);
char	*conv_percent( t_printf *printf_struct);
char	*conv_float(va_list ap, t_printf *ps);

/*
*---------------------handler_parse_flags.c-------------------------
*/
char	*flags_handler(char *str, t_printf *ps);
int		parse_flags(const char *input_str, int i, t_printf *printf_struct);

/*
*---------------------handler_infcase_negnb.c-------------------------
*/
char	*negnb_handler(char *str, t_printf *ps);
char	*inf_case_handler(char *str, t_printf *ps);
int 	count_dig(int nb);

/*
*---------------------put_char_firt.c-------------------------
*/
char 	*put_char_first(char *str, char c);

/*
*---------------------capitalize.c-------------------------
*/
char	*capitalize(char *str);

char	*exit_error(char *erinfo, t_printf *ps);

char	*pcf_skip_sp(char *str, char c);

void	free_str(char *str, char *str1);

#endif //FT_PRINTF_FT_PRINTF_H
