#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "src/write.h"
#include "src/write_util.h"
#include "src/ft_printf_utils.h"

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
    // ft_putnbr(num);


    // int num = 2147483647;

    // libc_cc =  printf("libc_printf: %X\n", num);
    // ft_cc = ft_printf("ft_printf  : %X\n", num);

    // libc_cc = printf("");
    // ft_cc = ft_printf(NULL);

    printf("char_counts:\n");
    printf("libc: %d\n  ft: %d\n", libc_cc, ft_cc);
}
