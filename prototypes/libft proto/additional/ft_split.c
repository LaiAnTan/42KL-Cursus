#include "libft.h"

static int 		countwords(char const *s, char c);
static int 		countletters(const char *s, char c, size_t start);
static char		**singlevalues(void);
static char 	**insertwords(char **strs, const char *s, char c, int nword);


char 	**ft_split(char const *s, char c)
{
	char **strs;
	int words;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (singlevalues());
	words = countwords(s, c);
	strs = (char **) malloc(sizeof(char *) * (words + 1));
	if (strs == 0)
		return (0);
	insertwords(strs, s, c, words);
	strs[words] = 0;
	return (strs);
}

static int countwords(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			i++;
			if (s[i] == c)
				count++;
			else if (s[i] == '\0' && ++count)
				break;
		}
	}
	return (count);
}

static int countletters(const char *s, char c, size_t start)
{
	int count;

	count = 0;
	while (s[start] != '\0')
	{
		if (s[start] == c)
			break;
		count++;
		start++;
	}
	return (count);
}

static char	**singlevalues(void)
{
	char	**strs;

	strs = (char **) malloc (1 * sizeof(char *));
	strs[0] = 0;
	return (strs);
}

static char **insertwords(char **strs, const char *s, char c, int nword)
{
	int j;
	size_t start;
	size_t end;

	j = 0;
	start = 0;
	while ((s[start] != '\0') || (s[end] != '\0'))
	{
		while (((s[start] == c) && (s[start + 1] == c)) || ((s[start] == c) && (s[start - 1] == c)) || (s[start] == c))
		{
			start++;
			if ((s[start] == '\0'))
				return (strs);
		}
		end = countletters(s, c, start) + start;
		strs[j++] = ft_substr(s, start, countletters(s, c, start));
		start = end;
	}
	return (strs);
}
