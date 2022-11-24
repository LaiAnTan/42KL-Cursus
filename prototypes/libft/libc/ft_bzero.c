#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	char *str = (char *) s;

	while (n)
	{
		str[n] = '\0';
		n--;
		if (!n)
		{
			str[n] = '\0';
			break;
		}
	}
}