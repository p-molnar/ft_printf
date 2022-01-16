/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:24:29 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/16 18:59:01 by pmolnar       ########   odam.nl         */
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
	size_t		printed_char_count;
	t_fmt_specs	fmt_specifier;

	printed_char_count = 0;
	i = 0;
	index_offset = 0;
	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			init_specifiers(&fmt_specifier);
			index_offset = parse_specifier(&format[i + 1], &fmt_specifier);	
			printed_char_count += print_arg(&fmt_specifier, &arg_list);
			i += index_offset;
		}
		else
			printed_char_count += write(1, &format[i], 1);
		i++;
	}
	va_end(arg_list);
	return (printed_char_count);
}

size_t	parse_specifier(const char *format_str, t_fmt_specs *fmt_specifiers)
{
	size_t	i;

	i = 0;
	i += populate_flags(&format_str[i], fmt_specifiers);
	i += populate_width(&format_str[i], fmt_specifiers);
	if (format_str[i] == '.')
		i++;	
	i += populate_precision(&format_str[i], fmt_specifiers);
	i += populate_specifier(&format_str[i], fmt_specifiers);

	// printf("neg_sign: %zu\n", (*fmt_specifiers).flag_negative_sign);
	// printf("pos_sign: %zu\n", (*fmt_specifiers).flag_positive_sign);
	// printf("zero: %zu\n", (*fmt_specifiers).flag_zero);
	// printf("hash: %zu\n", (*fmt_specifiers).flag_hash);
	// printf("space: %zu\n", (*fmt_specifiers).flag_space);
	// printf("width: %zu\n", (*fmt_specifiers).width);
	// printf("precision: %zu\n", (*fmt_specifiers).precision);
	// printf("specifier: %c\n", (*fmt_specifiers).specifier);
	// printf("---\n");
	return (i);
}

size_t	print_arg(t_fmt_specs *fmt_specs, va_list *arg_list)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	if ((*fmt_specs).specifier == 'c')
		printed_char_count += print_formatted_char(fmt_specs, va_arg(*arg_list, int));
	if ((*fmt_specs).specifier == 's')
		printed_char_count += print_formatted_str(fmt_specs, va_arg(*arg_list, char *));
	if ((*fmt_specs).specifier == 'p')
		printed_char_count += print_formatted_address(fmt_specs, va_arg(*arg_list, unsigned long));
	if ((*fmt_specs).specifier == 'd' || (*fmt_specs).specifier == 'i')
		printed_char_count += print_formatted_num(fmt_specs, va_arg(*arg_list, int));
	// if ((*fmt_specs).specifier == 'u')
	// 	printed_char_count += print_unsigned_num(va_arg(*arg_list, unsigned int));
	// if ((*fmt_specs).specifier == 'x')
	// 	printed_char_count += print_hex_num(va_arg(*arg_list, unsigned int), false);
	// if ((*fmt_specs).specifier == 'X')
	// 	printed_char_count += print_hex_num(va_arg(*arg_list, unsigned int), true);
	// if ((*fmt_specs).specifier == '%')
	// 	printed_char_count += print_formatted_char(fmt_specs, '%');
	return (printed_char_count);
}
