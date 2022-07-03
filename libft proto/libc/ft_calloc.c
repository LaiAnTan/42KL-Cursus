#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size);
void ft_bzero(void *s, size_t n);

void *ft_calloc(size_t nmemb, size_t size)
{
	void *str;

	if (!nmemb || !size)
		return (0);
	str = malloc(nmemb * size);
	if (!str)
		return (0);
	ft_bzero(str, (nmemb * size - 1));
	return (str);
}

