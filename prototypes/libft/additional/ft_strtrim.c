#include "libft.h"

static int charisvalid(char c, const char *set);

char 	*ft_strtrim(char const *s1, char const *set)
{
	char *str;
	size_t start;
	size_t end;
	size_t size;

	start = -1;
	size = ft_strlen(s1);
	end = size;
	if (!s1)
		return (0);
	if (!set)
		return (ft_substr(s1, 0, size));
	while (charisvalid(s1[++start], set))
		size--;
	if (start != end)
	{
		while(charisvalid(s1[--end], set))
			size--;
		str = ft_substr(s1, start, size);
	}
	else
		str = ft_substr("", 0, 0);
	if (!str)
		return (0);
	return (str);
	
}

static int charisvalid(char c, const char *set)
{
	int i;

	i = -1;
	while (set[++i] != '\0')
		if (set[i] == c)
			return (1);
	return (0);
}