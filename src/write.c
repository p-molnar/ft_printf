#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#include "write_util.h"
#include "ft_printf_utils.h"

#include <stdio.h>

#define HEX_PREFIX "0x"

size_t  ft_putchar(char c)
{
    return (write(1, &c, 1));
}

size_t  ft_putstr(char *s)
{
	size_t	printed_char_count;	
	
	printed_char_count = 0;
    if (s == NULL)
		printed_char_count += ft_putstr("(null)");
    printed_char_count += write(1, s, ft_strlen(s));
    return (printed_char_count);
}

size_t  ft_putnbr(int n) 
{
	size_t	printed_char_count;

	printed_char_count = 0;
	if (n == INT_MIN)
		printed_char_count += ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n == 0)
		printed_char_count += ft_putchar('0');
	else if (n < 10)
		printed_char_count += ft_putchar(n + '0');
	else
	{
		printed_char_count += ft_putnbr(n / 10);
		printed_char_count += ft_putnbr(n % 10);
	}
	return (printed_char_count);
}

size_t	ft_puthex(unsigned long n, bool put_in_capital)
{
	size_t	printed_char_count;
	char	*converted_num;

	converted_num = convert_dec_to_hex(n);
	if (put_in_capital == true)
		converted_num = ft_strupr(converted_num);
	printed_char_count = ft_putstr(converted_num);
	return (printed_char_count);
}

size_t	ft_put_address(unsigned long address)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	printed_char_count += ft_putstr(HEX_PREFIX);
	printed_char_count += ft_puthex(address, false);

	return (printed_char_count);
}
