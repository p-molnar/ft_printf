/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:24:29 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/21 13:47:01 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		arg_list;
	size_t		i;
	size_t		index_offset;
	size_t		char_count;
	t_fmt		fmt;

	char_count = 0;
	i = 0;
	index_offset = 0;
	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			init_specifiers(&fmt);
			index_offset = parse_specifier(&format[i + 1], &fmt);
			char_count += print_arg(&fmt, &arg_list);
			i += index_offset;
		}
		else
			char_count += write(1, &format[i], 1);
		i++;
	}
	va_end(arg_list);
	return (char_count);
}

size_t	parse_specifier(const char *format_str, t_fmt *fmt)
{
	size_t	i;

	i = 0;
	i += populate_flags(&format_str[i], fmt);
	i += populate_num(&format_str[i], &fmt->width);
	// i += populate_width(&format_str[i], fmt);
	if (format_str[i] == '.')
	{
		fmt->precision = 0;
		i++;
	}
	i += populate_num(&format_str[i], &fmt->precision);
	// i += populate_precision(&format_str[i], fmt);
	i += populate_specifier(&format_str[i], fmt);
	// if ((*fmt).precision_point)
	// {
	// 	if ((*fmt).precision < 0)
	// 		(*fmt).precision = 0;
	// }
	return (i);
}

size_t	print_arg(t_fmt *fmt, va_list *arg_list)
{
	size_t	char_count;

	char_count = 0;
	if (fmt->specifier == 'c')
		char_count += print_char(fmt, va_arg(*arg_list, int));
	else if (fmt->specifier == 's')
		char_count += print_str(fmt, va_arg(*arg_list, char *));
	else if (fmt->specifier == 'p')
		char_count += print_hex_num(fmt, va_arg(*arg_list, unsigned long));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		char_count += print_num(fmt, va_arg(*arg_list, int));
	else if (fmt->specifier == 'u')
		char_count += print_num(fmt, va_arg(*arg_list, unsigned int));
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		char_count += print_hex_num(fmt, va_arg(*arg_list, unsigned int));
	else if (fmt->specifier == '%')
		char_count += print_perc(fmt);
	return (char_count);
}
