#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{

    int libc_cc = 0;
    int ft_cc = 0;  

    // conversions: cspdiuxX%
    // %c print a single character.
    // %s print a string of characters.
    // %p The void * pointer argument is printed in hexadecimal. 
    // %d print a decimal (base 10) number.
    // %i print an integer in base 10.
    // %u print an unsigned decimal (base 10) number.
    // %x print a number in hexadecimal (base 16), with lowercase. 
    // %X print a number in hexadecimal (base 16), with uppercase. 
    // %% print a percent sign.
    // Manage any combination of the following flags: ’-0.’ and minimum field width with all conversions 
    // Manage all the following flags: ’# +’ (yes, one of them is a space)
    // int num = -2147483648;
    // put_nbr(num);


    // int num = 2147483647;

    // libc_cc =  printf("libc_printf: %X\n", num);
    // ft_cc = ft_printf("ft_printf  : %X\n", num);

    // ft_cc = ft_printf("libc: %p", &libc_cc);
    // printf("\n");
	// libc_cc = printf("  ft: %--+i", 35);
	// ft_cc = ft_printf("%-102.9134s, %p, %d, %i, %u, %x, %X, %%", "test", &ft_cc, 123, 123, 123, 132);
    libc_cc =      printf("|%#x|\n", &libc_cc);
    // (void) ft_cc
    ft_cc   =   ft_printf("|%#x|\n", &libc_cc);
    
    // printf("%d\n", ft_abs((int) 2147483648));
    // ft_put_nbr((int)-0);
    // printf("\n");
	// printf("\n");


    // printf("main: %d", get_max(10, 17, 16, 15, 14, 13, 12, 18, 19, 34, 1));

    // printf("char_counts:\n");
    // printf("libc: %d\n  ft: %d\n", libc_cc, ft_cc);
    // system("leaks a.out");
}
