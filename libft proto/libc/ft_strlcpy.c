#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t n;
	char *s = (char *) src;

	n = 0;
	if (size)
	{
		while((s[n] != '\0') && (n < size - 1))
		{
			dst[n] = s[n];
			n++;
		}
		dst[n] = '\0';
	}
	return (ft_strlen(s));
}