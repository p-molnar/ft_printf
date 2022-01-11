#include <stddef.h>

char    *convert_dec_to_hex(unsigned long n)
{
	size_t			pos;
	char	        *char_set;
	static char		converted_num[8 + 1];
    size_t          remainder;

	pos = 7;
	char_set = "0123456789abcdef";
	if (n == 0)
       return ("0");
	while (n)
	{
        remainder = n % 16;
		converted_num[pos--] = char_set[remainder];
		n /= 16;
	}
	return (&converted_num[++pos]);
}

int  ft_index_of(const char str[], char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}