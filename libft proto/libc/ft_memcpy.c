#include "libft.h"

void *ft_memcpy(void *d, const void *s, size_t n);

void *ft_memcpy(void *d, const void *s, size_t n)
{
	int i;
	char *src = (char *) s;
	char *dst = (char *) d;

	i = 0;
	while (n)
	{
		dst[i] = src[i];
		n--;
		i++;
	}
	return (d);
}