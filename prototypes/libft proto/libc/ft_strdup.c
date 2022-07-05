#include "libft.h"

char *ft_strdup(const char *s)
{
	int i;
	char *str = (char *) s;
	char *dest;

	i = 0;
	dest = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == 0)
		return  (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		dest[i] = '\0';
	return (dest);
}