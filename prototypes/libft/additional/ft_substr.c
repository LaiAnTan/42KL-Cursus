#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
	size_t i;

    i = -1;
    str = (char *) malloc(sizeof(char) * len + 1);
    if (str == 0)
        return (0);
    while (++i < len && s[start])
    {
        str[i] = s[start];
        start++;
    }
	str[i] = '\0';
    return (str);
}

