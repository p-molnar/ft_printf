#include "../ft_printf.h"
#include "../libft/libft.h"

#include <limits.h>
#include <unistd.h>
#include <stdbool.h>


size_t	ft_put_char(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_put_str(char *s, size_t len)
{
	size_t	printed_char_count;	

	printed_char_count = 0;
	printed_char_count += write(1, s, len);
	return (printed_char_count);
}

size_t	ft_put_nbr(long long n)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	if (n == INT_MIN)
		printed_char_count += ft_put_str("2147483648", 10);
	else if (n < 0)
		printed_char_count += ft_put_nbr(-n);
	else if (n == 0)
		printed_char_count += ft_put_char('0');
	else if (n < 10)
		printed_char_count += ft_put_char(n + '0');
	else
	{
		printed_char_count += ft_put_nbr(n / 10);
		printed_char_count += ft_put_nbr(n % 10);
	}
	return (printed_char_count);
}

size_t	ft_put_hex(unsigned long n, bool put_in_capital)
{
	size_t	printed_char_count;
	char	*converted_num;

	converted_num = convert_dec_to_hex(n);
	if (put_in_capital == true)
		converted_num = ft_strupr(converted_num);
	printed_char_count = ft_put_str(converted_num, ft_strlen(converted_num));
	return (printed_char_count);
}

size_t	ft_put_address(unsigned long address)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	printed_char_count += ft_put_str(HEX_PREFIX_LOWER, ft_strlen(HEX_PREFIX_LOWER));
	printed_char_count += ft_put_hex(address, false);
	return (printed_char_count);
}