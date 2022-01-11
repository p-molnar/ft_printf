#include <stddef.h>
#include <ctype.h>
#include <libc.h>

size_t  ft_strlen(const char *s)
{   
    size_t  i;
    size_t  char_count;

    i = 0;
    char_count = 0;
    while (s && s[i++])
        char_count++;
    
    return (char_count);
}

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return ((unsigned int)(c - ('a' - 'A')));
    return (c);
}

char    *ft_strupr(char *s)
{
    size_t  i;

    i = 0;
    if (!s)
        return (NULL);
    while (s[i]) 
    {
        s[i] = ft_toupper(s[i]);
        i++;
    }
    return (s);
}

