#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

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

size_t	print_width(t_fmt_specs *fmt_specs, int n, size_t nbr_len)
{
	size_t	printed_char_count;
	size_t	full_length;
	size_t	width;
	size_t	precision;


	printed_char_count = 0;
	full_length = get_max(3, (*fmt_specs).width, (*fmt_specs).precision, nbr_len);
	precision = get_max(2, (*fmt_specs).precision - nbr_len, 0);
	nbr_len += ((*fmt_specs).flag_positive_sign > 0);
	nbr_len += ((*fmt_specs).flag_space > 0);
	nbr_len += ((*fmt_specs).flag_zero > 0);
	nbr_len += (n < 0);
	// printf("full_length: %d\n", (int) full_length);
	// printf("precision: %d\n", (int) precision);
	width = get_max(2, full_length - precision - nbr_len, 0);
	// printf("width: %d\n", (int) width);
	printed_char_count += iter_fn_n_times(ft_put_char, CHAR_SPACE, width);
	return (printed_char_count);
}

size_t	print_precision(t_fmt_specs *fmt_specs, size_t nbr_len)
{
	size_t	printed_char_count;
	size_t	full_length;
	size_t	precision;

	printed_char_count = 0;
	full_length = get_max(3, (*fmt_specs).width, (*fmt_specs).precision, nbr_len);
	// printf("full_length: %zu\n", full_length);
	precision = get_max(2, (*fmt_specs).precision - nbr_len, 0);
	// printf("precision: %zu\n", precision);
	printed_char_count += iter_fn_n_times(ft_put_char, CHAR_ZERO, precision);
	return (printed_char_count);
}

size_t	print_prefix(t_fmt_specs *fmt_specs, int *n, size_t *nbr_len)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	if (*n < 0)
	{
		printed_char_count += ft_put_char(CHAR_MINUS);
		*n = ft_abs(*n);
		(void) nbr_len;
	}
	if ((*fmt_specs).flag_positive_sign)
		printed_char_count += ft_put_char(CHAR_PLUS);
	else if ((*fmt_specs).flag_space)
		printed_char_count += ft_put_char(CHAR_SPACE);
	else if ((*fmt_specs).flag_zero)
		printed_char_count += ft_put_char(CHAR_ZERO);
	return (printed_char_count);
}