#include "../ft_printf.h"

size_t	iter_fn_n_times(size_t (*fn)(int c), int fn_arg, size_t n)
{
	size_t	i;
	size_t	printed_char_count;

	i = 0;
	printed_char_count = 0;

	while (i < n)
	{
		printed_char_count += fn(fn_arg);
		i++;
	}
	return (printed_char_count);
}