/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:43:18 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/15 14:03:38 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


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
