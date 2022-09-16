#include "get_next_line.h"

char	*ft_append(char *src, char *dst)
{
	int		srclen;
	int		dstlen;
	char	*append;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	append = (char *) malloc (sizeof(char) * (srclen + dstlen + 1));
	if (!append)
		return (0);
	while (*src != '\0')
	{
		*append = *src;
		append++;
		src++;
	}
	while (*dst != '\0')
	{
		*append = *dst;
		append++;
		dst++;
	}
	return (append);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}