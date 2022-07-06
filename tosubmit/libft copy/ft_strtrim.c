#include "libft.h"

static int checkfront(const char *s, const char *set, size_t setlen);
static int checkback(const char *s, const char *set, size_t slen, size_t setlen);

char 	*ft_strtrim(char const *s1, char const *set)
{
	char *str;
	int trimcnt;
	size_t s1size;
	size_t setsize;

	trimcnt = 0;
	s1size = ft_strlen(s1);
	setsize = ft_strlen(set);
	if (checkfront(s1, set, setsize))
	{
		str = ft_substr(s1, setsize, s1size);
		trimcnt = 1;
	}
	if (checkback(s1, set, s1size, setsize))
	{
		trimcnt = 1;
		str = ft_substr(str, 0, (s1size - setsize - setsize));
	}
	if (!trimcnt)
		str = (char *) s1;
	return (str);
	
}

static int checkfront(const char *s, const char *set, size_t setlen)
{
	int i;

	i = 0;
	while((setlen) && (set[i] != '\0'))
	{
		if (set[i] == s[i])
		{
			i++;
			setlen--;
		}
		else
			break;

	}
	if (!setlen)
		return (1);
	else	
		return (0);
}

static int checkback(const char *s, const char *set, size_t slen, size_t setlen)
{
	size_t i;

	i = slen - setlen;
	while (slen > i)
	{
		if(s[slen] == set[setlen])
		{
			slen--;
			setlen--;
		}
		else
			break;
	}
	if (!setlen)
		return (1);
	else
		return (0);
}