#include "includes/ft_printf.h"


void	fix_flag_errors(t_printf *ps)
{
    if (ps->is_nan)
    {
        ps->is_plus = 0;
        ps->is_space = 0;
    }
    if (ps->is_plus && ps->conversion == 'u')
        ps->is_plus = 0;
    if (ps->is_space && ps->conversion == 'u')
        ps->is_space = 0;
    if (ps->zero_arg && ps->conversion != 'f' && ps->conversion != 'F')
        ps->is_hash = 0;
    if (ps->conversion == 'x' || ps->conversion == 'X' || ps->conversion == 'p' ||
        ps->conversion == 'o' || ps->conversion == 's' || ps->conversion == 'c')
    {
        ps->is_plus = 0;
        ps->is_space = 0;
    }
    if (ps->is_space && (ps->conversion == 'f' || ps->conversion == 'F'))
        ps->is_zero = 0;
    if ((ps->accuracy || ps->is_minus) && ps->conversion != 'f' && ps->conversion != 'F')
        ps->is_zero = 0;
    if (ps->is_plus)
        ps->is_space = 0;
    if (ps->conversion == 'c' || ps ->conversion == '%')
    {
        ps->accuracy = 0;
        ps->is_space = 0;
        ps->is_plus = 0;
    }
    if (ps->conversion == 'p')
        ps->is_hash = 1;
}