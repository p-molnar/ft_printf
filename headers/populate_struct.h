/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate_struct.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 14:03:50 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/21 19:59:22 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include "../ft_printf_cust_data_types"
#include <stdbool.h>

void	init_fmt_struct(t_fmt *fmt);
size_t	populate_flags(const char *str, t_fmt *fmt);
size_t	populate_num(const char *str, int *n);
size_t	populate_specifier(const char *str, t_fmt *fmt_specs);