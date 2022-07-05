#include "libft.h"

char 	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	int len;
	char *str;

	i = -1;
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * len);
	while (s[++i] != '\0')
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}