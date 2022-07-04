#include "libft.h"

char 	*ft_strtrim(char const *s1, char const *set)
{
	char *str;
	char *end;
	int i;
	size_t sizes1;
	size_t sizeset;

	i = 0;
	sizes1 = ft_strlen(s1);
	sizeset = ft_strlen(set);
	str = ft_substr(s1, sizeset, sizes1);

	printf("%p\n", end);
	return (str);
}

