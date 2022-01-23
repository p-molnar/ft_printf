#ifndef PRINTF_ARG_PRINTER_H
# define PRINTF_ARG_PRINTER_H
# include "ft_printf_cust_data_types.h"

size_t	print_char(t_fmt *fmt, int c);
size_t	print_str(t_fmt *fmt, char *str);
size_t	print_num(t_fmt *fmt, long long n);
size_t	print_hex_num(t_fmt *fmt, long long n);
size_t	print_perc(t_fmt *fmt);

#endif