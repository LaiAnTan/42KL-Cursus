#include "libft.h"

size_t ft_strlcat(char *d, const char *s, size_t size)
{
	size_t n;
	size_t dlen;
	size_t slen;
	int m;

	char *src = (char *) s;
	dlen = ft_strlen(d);
	slen = ft_strlen(s);
	n = dlen;
	m = 0;
	if (size == 0 || dlen > size)
		return (size + slen);
	while ((n < size - 1) && (src[m] != '\0'))
	{
		d[n] = src[m];
		n++;
		m++;
	}
	d[n] = '\0';
	return (dlen + slen);
}