/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_arg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:49:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/16 18:59:37 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#define CHAR_SPACE ' '

size_t	print_formatted_char(t_fmt_specs *fmt_specs, int c)
{
	size_t	printed_char_count;
	size_t	repeat_count;

	printed_char_count = 0;
	if ((*fmt_specs).width > 1)
	{
		repeat_count = (*fmt_specs).width - 1;
		if ((*fmt_specs).flag_negative_sign)
		{
			printed_char_count += ft_put_char(c);
			printed_char_count += iter_fn_n_times(&ft_put_char, CHAR_SPACE, repeat_count);
		}
		else
		{
			printed_char_count += iter_fn_n_times(&ft_put_char, CHAR_SPACE, repeat_count);
			printed_char_count += ft_put_char(c);
		}
	}
	else
		printed_char_count += ft_put_char(c);
	return (printed_char_count);
}

size_t	print_formatted_str(t_fmt_specs *fmt_specs, char *str)
{
	size_t	printed_char_count;
	size_t	repeat_count;

	printed_char_count = 0;
	if ((*fmt_specs).width > ft_strlen(str))
	{
		repeat_count = (*fmt_specs).width - ft_strlen(str);
		if ((*fmt_specs).flag_negative_sign)
		{
			printed_char_count += ft_put_str(str);
			printed_char_count += iter_fn_n_times(&ft_put_char, CHAR_SPACE, repeat_count);
		}
		else
		{
			printed_char_count += iter_fn_n_times(&ft_put_char, CHAR_SPACE, repeat_count);
			printed_char_count += ft_put_str(str);
		}
	}
	else
		printed_char_count += ft_put_str(str);
	return (printed_char_count);
}

size_t	print_formatted_address(t_fmt_specs *fmt_specs, unsigned long address)
{
	char 	*converted_address;
	size_t	printed_char_count;

	printed_char_count = 0;
	converted_address = convert_dec_to_hex(address);
	converted_address = ft_strjoin(HEX_PREFIX, converted_address);
	if (!converted_address)
		return (0);
	printed_char_count += print_formatted_str(fmt_specs, converted_address);
	free(converted_address);
	return (printed_char_count);
}

size_t	print_formatted_num(t_fmt_specs *fmt_specs, int n)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	(void) fmt_specs;
	printed_char_count += ft_put_nbr(n);
	return (printed_char_count);
}