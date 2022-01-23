#ifndef FT_PRINTF_ARG_FORMATTER_H
# define FT_PRINTF_ARG_FORMATTER_H
# include "ft_printf_cust_data_types.h"

size_t	add_width(size_t n);
size_t	add_precision(size_t n);
size_t	add_prefix(t_fmt *fmt, long long n);
size_t	calc_precision(t_fmt *fmt, long long n, t_print_fmt p_fmt);
size_t	calc_width(t_fmt *fmt, long long n, t_print_fmt p_fmt);

#endif