#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;
	char *str1 = (char *) s1;
	char *str2 = (char *) s2;

	i = 0;
	while ((n) && (str1[i] != '\0') && (str2[i] != '\0'))
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return(-1);
		else
		{
			i++;
			n--;
		}
	}
	return (0);
}