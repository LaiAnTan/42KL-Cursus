#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int n;
	char *str;
	
	n = 0;
	str = (char *) s;
	if (!str)
		return (0);
	while (str[n] != '\0')
	{
		if (str[n] == c)
		{
			return (&str[n]);
		}
		n++;
	}
	if (c == '\0')
		return (&str[n]);
	return (0);
}