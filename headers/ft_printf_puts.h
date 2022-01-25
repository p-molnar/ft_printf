#ifndef FT_PRINTF_PUTS_H
# define FT_PRINTF_PUTS_H
# include <stddef.h>

size_t	ft_put_char(int c);
size_t	ft_put_str(char *s, size_t len);
size_t	ft_put_nbr(long long n);
#endif