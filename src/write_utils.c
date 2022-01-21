/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:51:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/21 13:00:04 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strupr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

char	*convert_dec_to_hex(unsigned long n)
{
	size_t			pos;
	char			*char_set;
	static char		converted_num[16 + 1];
	size_t			remainder;

	pos = 15;
	char_set = "0123456789abcdef";
	if (n == 0)
	{
		converted_num[0] = '0';
		return (converted_num);
	}
	while (n)
	{
		remainder = n % 16;
		converted_num[pos--] = char_set[remainder];
		n /= 16;
	}
	return (&converted_num[++pos]);
}
