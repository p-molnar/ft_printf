/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/14 23:39:11 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/21 13:53:40 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>

# define HEX_PREFIX_LOWER "0x"
# define HEX_PREFIX_UPPER "0X"
# define PRINTF_FLAGS "-+ #0"
# define PRINTF_SPECIFIERS "cspdiuxX%"
# define CHAR_SPACE ' '
# define CHAR_ZERO '0'
# define CHAR_PLUS '+'
# define CHAR_MINUS '-'
# define CHAR_PERC '%'

typedef struct s_print
{
	size_t		total_len;
	size_t		arg_len;
	size_t		width;
	size_t		precision;

}				t_print_fmt;

typedef struct s_flags
{
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
}				t_flags;

typedef struct s_fmt
{
	t_flags	flags;
	int		width;
	int		precision;
	char	specifier;
}				t_fmt;

// ft_printf.c
int		ft_printf(const char *format, ...);
size_t	parse_specifier(const char *format_str, t_fmt *fmt);
size_t	print_arg(t_fmt *fmt_specs, va_list *args);

// ft_printf_utils.h
int		index_of(const char str[], char c);
int		get_max(size_t arg_count, ...);
size_t	get_num_len(long long n);

// print_arg.c
size_t	print_char(t_fmt *fmt, int c);
size_t	print_str(t_fmt *fmt, char *str);
size_t	print_address(t_fmt *fmt, unsigned long address);
size_t	print_num(t_fmt *fmt, long long n);
size_t	print_hex_num(t_fmt *fmt, long long n);
size_t	print_perc(t_fmt *fmt);

// print_arg_utils.c
size_t	add_padding(size_t n);
size_t	add_precision(size_t n);
size_t	calc_precision(t_fmt *fmt, long long n, t_print_fmt p_fmt);
size_t	calc_width(t_fmt *fmt, long long n, t_print_fmt p_fmt);
size_t	add_prefix(t_fmt *fmt, long long n);

// put.c
size_t	ft_put_char(int c);
size_t	ft_put_str(char *s, size_t len);
size_t	ft_put_nbr(long long n);
size_t	ft_put_hex(unsigned long n, bool put_in_capital);
size_t	ft_put_address(unsigned long address);
size_t	ft_put_unsigned_nbr(unsigned int n);

// write_utils.c
char	*convert_dec_to_hex(unsigned long n);
char	*ft_strupr(char *s);

// populate_specifiers_struct.c
void	init_specifiers(t_fmt *fmt);
size_t	populate_flags(const char *str, t_fmt *fmt);
size_t	populate_width(const char *str, t_fmt *fmt_specs);
size_t	populate_num(const char *str, int *n);
size_t	populate_precision(const char *str, t_fmt *fmt_specs);
size_t	populate_specifier(const char *str, t_fmt *fmt_specs);
void	increment_flag_count(int *flag_count);
#endif