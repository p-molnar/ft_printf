#include "../ft_printf.h"
#include "parse.h"
#include <stdarg.h>

size_t	parse_formatting(const char *format_str, t_fmt *fmt)
{
	size_t	i;

	i = 0;
	i += populate_flags(&format_str[i], fmt);
	i += populate_num(&format_str[i], &fmt->width);
	if (format_str[i] == '.')
	{
		fmt->precision = 0;
		i++;
	}
	i += populate_num(&format_str[i], &fmt->precision);
	i += populate_specifier(&format_str[i], fmt);
	return (i);
}
