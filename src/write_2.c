#include <limits.h>
#include <stddef.h>

#include "write.h"

size_t  ft_putunbr(unsigned int n) 
{
	size_t	printed_char_count;

	printed_char_count = 0;
	if (n == 0)
		printed_char_count += ft_putchar('0');
	else if (n < 10)
		printed_char_count += ft_putchar(n + '0');
	else
	{
		printed_char_count += ft_putunbr(n / 10);
		printed_char_count += ft_putunbr(n % 10);
	}
	return (printed_char_count);
}