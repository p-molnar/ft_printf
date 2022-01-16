/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate_specifier_struct.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 14:03:50 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/15 18:23:44 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	init_specifiers(t_fmt_specs *fmt_specs)
{
	(*fmt_specs).flag_negative_sign = false;
	(*fmt_specs).flag_positive_sign = false;
	(*fmt_specs).flag_space = false;
	(*fmt_specs).flag_hash = false;
	(*fmt_specs).flag_zero = false;
	(*fmt_specs).width = 0;
	(*fmt_specs).precision = 0;
	(*fmt_specs).specifier = '\0';
}

size_t	populate_flags(const char *str, t_fmt_specs *fmt_specs)
{
	size_t	i;
	char	flag;

	i = 0;
	while(index_of(PRINTF_FLAGS, str[i]) >= 0)
	{
		flag = str[i];
		if (flag == '-')
			(*fmt_specs).flag_negative_sign++;
		if (flag == '+')
			(*fmt_specs).flag_positive_sign++;
		if (flag == '0')
			(*fmt_specs).flag_zero++;
		if (flag == '#')
			(*fmt_specs).flag_hash++;
		if (flag == ' ')
			(*fmt_specs).flag_space++;
		i++;
	}
	return (i);
}

size_t	populate_width(const char *str, t_fmt_specs *fmt_specs)
{
	size_t	width;
	size_t	i;

	width = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		width = 10 * width + (str[i] - '0');
		i++;
	}
	(*fmt_specs).width = width;
	return (i);
}

size_t	populate_precision(const char *str, t_fmt_specs *fmt_specs)
{
	size_t	precision;
	size_t	i;

	precision = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		precision = 10 * precision + (str[i] - '0');
		i++;
	}
	(*fmt_specs).precision = precision;
	return (i);
}

size_t	populate_specifier(const char *str, t_fmt_specs *fmt_specs)
{
	char	specifier;

	specifier = str[0];
	if (index_of(PRINTF_SPECIFIERS, specifier) >= 0)
		(*fmt_specs).specifier = specifier;
	return (1);
}