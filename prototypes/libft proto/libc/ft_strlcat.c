#include "libft.h"

size_t ft_strlcat(char *d, const char *s, size_t size)
{
	size_t n;
	int m;
	char *src = (char *) s;
	
	n = ft_strlen(d);
	m = 0;
	while ((n < size - 1) && (src[m] != '\0'))
	{
		d[n] = src[m];
		n++;
		m++;
	}
	d[n] = '\0';
	return (ft_strlen(d) + ft_strlen(src));
}