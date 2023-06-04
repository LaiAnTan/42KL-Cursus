#include "libft.h"

char 	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	int len;
	char *str;

	i = 0;
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * len + 1);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}