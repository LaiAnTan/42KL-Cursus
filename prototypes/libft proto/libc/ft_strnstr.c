#include "libft.h"

static int check(char *big, char *little, int j);

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	int j;
	char *occ;
	char *s1 = (char *) big;
	char *s2 = (char *) little;

	j = 0;
	if (!ft_strlen(s2))
		return (s1);
	while ((len) && (s1[j] != '\0'))
	{
		if(s2[0] == s1[j])
		{
			if (check(s2, s1, j))
			{
				occ = &s2[j];
				return (occ);
			}
		}
		j++;
		len--;
	}
	return (0);
}

int check(char *big, char *little, int j)
{
	size_t i;

	i = 0;
	while ((big[j] != '\0') && (little[i] != '\0'))
	{
		if(little[i] == big[j])
			i++;
		j++;
	}
	if(i == ft_strlen(little))
		return (1);
	else
		return (0);
}