#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	int m;
	char *occ;
	char *src = (char *) s;
	m = 0;
	while (n)
	{
		if (src[n] == c)
		{
			occ = &src[n];
			return (occ);
		}
		n--;
		m++;
	}
	return (0);
}