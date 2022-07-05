#include "libft.h"

void *ft_memmove(void *d, const void *s, size_t n)
{
	char * src = (char *) s;
	char * dest = (char *) d;
	while (n-- > 0)
		dest[n] = src[n];
	return (d);
}