#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int n;
	char *str;

	str = (char *) s;
	n = ft_strlen(str);
	if (!str)
		return (0);
	while (n >= 0)
	{
		if (str[n] == c)
			return (&str[n]);
		n--;
	}
	if (c == '\0')
		return (&str[n]);
	return (0);
}