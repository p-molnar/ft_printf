/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/14 23:39:11 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/16 23:06:10 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>

# define HEX_PREFIX "0x"
# define PRINTF_FLAGS "-+ #0"
# define PRINTF_SPECIFIERS "cspdiuxX%"

typedef struct	s_fmt_specs
{
	size_t 	flag_negative_sign;
	size_t 	flag_positive_sign;
	size_t 	flag_space;
	size_t 	flag_hash;
	size_t 	flag_zero;
	size_t	width;
	size_t	precision;
	char	specifier;
}				t_fmt_specs;

// ft_printf.c
int		ft_printf(const char *format, ...);
size_t	parse_specifier(const char *format_str, t_fmt_specs *specifier_struct);
size_t	print_arg(t_fmt_specs *fmt_specs, va_list *args);

// ft_printf_utils.h
int		index_of(const char str[], char c);
int		get_max(int n1, int n2);

// print_arg.c
size_t	print_formatted_char(t_fmt_specs *fmt_specs, int c);
size_t	print_formatted_str(t_fmt_specs *fmt_specs, char *str);
size_t	print_formatted_address(t_fmt_specs *fmt_specs, unsigned long address);
size_t	print_formatted_num(t_fmt_specs *fmt_specs, int n);
size_t	print_unsigned_num(unsigned int n);
size_t	print_hex_num(unsigned long n, bool put_in_capital);

// print_arg_utils.c
size_t	iter_fn_n_times(size_t (*fn)(int c), int fn_arg, size_t n);

// put.c
size_t	ft_put_char(int	c);
size_t	ft_put_str(char *s);
size_t	ft_put_nbr(int n);
size_t	ft_put_hex(unsigned long n, bool put_in_capital);
size_t	ft_put_address(unsigned long address);
size_t	ft_put_unsigned_nbr(unsigned int n);

// write_utils.c
char	*convert_dec_to_hex(unsigned long n);
char	*ft_strupr(char *s);

// populate_specifiers_struct.c
void	init_specifiers(t_fmt_specs *fmt_specs);
size_t	populate_flags(const char *str, t_fmt_specs *fmt_specs);
size_t	populate_width(const char *str, t_fmt_specs *fmt_specs);
size_t	populate_precision(const char *str, t_fmt_specs *fmt_specs);
size_t	populate_specifier(const char *str, t_fmt_specs *fmt_specs);
#endif