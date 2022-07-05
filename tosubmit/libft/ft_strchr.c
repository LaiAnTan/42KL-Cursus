#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int n;
	char *occ;
	char *str = (char *) s;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] == c)
		{
			occ = &str[n];
			return (occ);
		}
		n++;
	}
	return (0);
}