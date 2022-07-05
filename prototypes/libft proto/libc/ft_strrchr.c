#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int n;
	char *occ;
	char *str = (char *) s;

	n = ft_strlen(str);
	while (n)
	{
		if (str[n] == c)
		{
			occ = &str[n];
			return (occ);
		}
		n--;
	}
	return (0);
}