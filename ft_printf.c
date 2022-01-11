#include <stdarg.h>
#include <stddef.h>

#include "src/ft_printf_utils.h"
#include "src/write.h"

#include <stdio.h>
#include <string.h>

int ft_printf(const char *format, ...)
{
    va_list arg_list;
    size_t  printed_char_count;

    va_start(arg_list, format);
    printed_char_count = print_args(format, arg_list);
    va_end(arg_list);

    return (printed_char_count);
}

size_t	print_args(const char *format_string, va_list arg_list)
{
    size_t  i;
    size_t  printed_char_count;
    char    *specifier_set;
    int     specifier_index;
    char    applied_specifier;
    
    i = 0;
    printed_char_count = 0;
    specifier_set = "cspdiuxX%";
    while (format_string[i])
    {   
        specifier_index = ft_index_of(specifier_set, format_string[i + 1]);
        if (format_string[i] == '%' && specifier_index >= 0)
        {   
            applied_specifier = specifier_set[specifier_index];
            printed_char_count += print_specifier(applied_specifier, arg_list);
            i++;
        }
        else
            printed_char_count += ft_putchar(format_string[i]);
        i++;      
    }
    return (printed_char_count);
}

size_t	print_specifier(char specifier, va_list arg_list)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	if (specifier == 'c')
		printed_char_count += ft_putchar(va_arg(arg_list, int));
    if (specifier == 's')
		printed_char_count += ft_putstr(va_arg(arg_list, char *));
    if (specifier == 'p')
		printed_char_count += ft_put_address(va_arg(arg_list, unsigned long));
    if (specifier == 'd' || specifier == 'i')
        printed_char_count += ft_putnbr(va_arg(arg_list, int));
    if (specifier == 'u')
        printed_char_count += ft_putunbr(va_arg(arg_list, unsigned int));
    if (specifier == 'x')
        printed_char_count += ft_puthex(va_arg(arg_list, unsigned long), false);
    if (specifier == 'X')
        printed_char_count += ft_puthex(va_arg(arg_list, unsigned long), true);
    if (specifier == '%')
        printed_char_count += ft_putchar('%');
    return (printed_char_count);
}
