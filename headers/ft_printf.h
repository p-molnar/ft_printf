/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/14 23:39:11 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/21 19:46:13 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>



int		ft_printf(const char *format, ...);
size_t	print_arg(t_fmt *fmt, va_list *arg_list)


// print_arg_utils.c
size_t	add_width(size_t n);
size_t	add_precision(size_t n);
size_t	calc_precision(t_fmt *fmt, long long n, t_print_fmt p_fmt);
size_t	calc_width(t_fmt *fmt, long long n, t_print_fmt p_fmt);
size_t	add_prefix(t_fmt *fmt, long long n);

// write_utils.c


// populate_specifiers_struct.c
void	init_fmt_struct(t_fmt *fmt);
size_t	populate_flags(const char *str, t_fmt *fmt);
size_t	populate_num(const char *str, int *n);
size_t	populate_specifier(const char *str, t_fmt *fmt_specs);
#endif