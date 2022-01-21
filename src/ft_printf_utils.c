/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:43:18 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/21 11:45:55 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	index_of(const char str[], char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_max(size_t arg_count, ...)
{
	size_t	i;
	va_list	args;
	int		arg;
	int		max;

	i = 0;
	va_start(args, arg_count);
	max = va_arg(args, int);
	while (i < (arg_count - 1))
	{
		arg = va_arg(args, int);
		if (arg > max)
			max = arg;
		i++;
	}	
	va_end(args);
	return (max);
}

size_t	get_num_len(long long n)
{
	size_t	len;

	len = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
