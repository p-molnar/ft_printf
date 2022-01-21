/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_arg_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 19:37:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/21 13:50:59 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

size_t	add_padding(size_t n)
{
	size_t	i;
	size_t	printed_char_count;

	i = 0;
	printed_char_count = 0;
	while (i < n)
	{
		printed_char_count += ft_put_char(CHAR_SPACE);
		i++;
	}
	return (printed_char_count);
}

size_t	add_precision(size_t n)
{
	size_t	i;
	size_t	printed_char_count;

	i = 0;
	printed_char_count = 0;
	while (i < n)
	{
		printed_char_count += ft_put_char(CHAR_ZERO);
		i++;
	}
	return (printed_char_count);
}

size_t	calc_precision(t_fmt *fmt, long long n, t_print_fmt p_fmt)
{
	size_t	precision;

	precision = get_max(2, fmt->precision - p_fmt.arg_len, 0);
	if (fmt->flags.zero != -1 && fmt->precision == (-1))
		precision = get_max(2, fmt->width - p_fmt.arg_len - (n < 0), 0);
	return (precision);
}

size_t	calc_width(t_fmt *fmt, long long n, t_print_fmt p_fmt)
{
	size_t	width;

	width = get_max(2, p_fmt.total_len - p_fmt.precision \
	- p_fmt.arg_len - (n < 0), 0);
	if ((fmt->flags.space != -1 || fmt->flags.plus != -1) \
	&& (fmt->specifier == 'd' || fmt->specifier == 'i'))
		width = get_max(2, width - 1, 0);
	else if (n == 0 && fmt->precision != -1 && fmt->specifier != '%')
		width = get_max(2, fmt->width - fmt->precision, 0);
	else if (n != 0 && fmt->flags.hash != -1)
		width = get_max(2, width - 2, 0);
	else if (fmt->specifier == 'p')
		width = get_max(2, width - 2, 0);
	return (width);
}

size_t	add_prefix(t_fmt *fmt, long long n)
{
	size_t	printed_char_count;	

	printed_char_count = 0;
	if (fmt->flags.space != -1 && n >= 0)
		printed_char_count += ft_put_char(CHAR_SPACE);
	else if (n < 0 && fmt->specifier != 'p')
		printed_char_count += ft_put_char(CHAR_MINUS);
	else if (fmt->flags.plus != -1 && n >= 0)
		printed_char_count += ft_put_char(CHAR_PLUS);
	else if (fmt->flags.hash != -1 && n != 0 && fmt->specifier == 'x')
		printed_char_count += ft_put_str(HEX_PREFIX_LOWER, 2);
	else if (fmt->flags.hash != -1 && n != 0 && fmt->specifier == 'X')
		printed_char_count += ft_put_str(HEX_PREFIX_UPPER, 2);
	else if (fmt->specifier == 'p')
		printed_char_count += ft_put_str(HEX_PREFIX_LOWER, 2);
	return (printed_char_count);
}
