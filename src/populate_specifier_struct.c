/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate_specifier_struct.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 14:03:50 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/21 13:51:26 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	init_specifiers(t_fmt *fmt)
{
	fmt->flags.minus = -1;
	fmt->flags.plus = -1;
	fmt->flags.space = -1;
	fmt->flags.hash = -1;
	fmt->flags.zero = -1;
	fmt->width = -1;
	fmt->precision = -1;
	fmt->specifier = '\0';
}

size_t	populate_flags(const char *str, t_fmt *fmt)
{
	size_t	i;
	char	flag;

	i = 0;
	while (index_of(PRINTF_FLAGS, str[i]) >= 0)
	{
		flag = str[i];
		if (flag == '-')
			increment_flag_count(&fmt->flags.minus);
		if (flag == '+')
			increment_flag_count(&fmt->flags.plus);
		if (flag == '0')
			increment_flag_count(&fmt->flags.zero);
		if (flag == '#')
			increment_flag_count(&fmt->flags.hash);
		if (flag == ' ')
			increment_flag_count(&fmt->flags.space);
		i++;
	}
	return (i);
}

size_t	populate_num(const char *str, int *n)
{
	size_t	num;
	size_t	num_len;

	if (!ft_isdigit(str[0]))
		return (0);
	num = ft_atoi(str);
	*n = num;
	num_len = get_num_len(num);
	return (num_len);
}

size_t	populate_specifier(const char *str, t_fmt *fmt_specs)
{
	char	specifier;

	specifier = str[0];
	if (index_of(PRINTF_SPECIFIERS, specifier) >= 0)
		(*fmt_specs).specifier = specifier;
	return (1);
}

void	increment_flag_count(int *flag_count)
{
	if (*flag_count < 0)
		*flag_count = 0;
	*flag_count = *flag_count + 1;
}
