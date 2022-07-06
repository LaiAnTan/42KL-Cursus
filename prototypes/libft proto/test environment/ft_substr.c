#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    int i;
    int j;

    i = 0;
    j = len;
    str = (char *) malloc(sizeof(char) * j);
    if (str == 0)
        return (0);
    while (j)
    {
        str[i] = s[start];
        i++;
        start++;
        j--;
    }
	str[i] = '\0';
    return (str);
}