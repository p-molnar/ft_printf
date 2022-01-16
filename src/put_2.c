/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:55:11 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/16 14:52:19 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_put_unsigned_nbr(unsigned int n)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	if (n == 0)
		printed_char_count += ft_put_char('0');
	else if (n < 10)
		printed_char_count += ft_put_char(n + '0');
	else
	{
		printed_char_count += ft_put_unsigned_nbr(n / 10);
		printed_char_count += ft_put_unsigned_nbr(n % 10);
	}
	return (printed_char_count);
}
