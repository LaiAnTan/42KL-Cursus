#include "libft.h"

static int 		countwords(char const *s, char c);
static int 		countletters(const char *s, char c, size_t start);
static char  	**memwords(const char *s, char c);
static char 	**insertwords(char **strs, const char *s, char c, int nword);

char 	**ft_split(char const *s, char c)
{
	char **strs;
	int words;

	words = countwords(s, c);
	strs = memwords(s, c);
	insertwords(strs, s, c, words);
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
			{
				count++;
			}
			else if (s[i] == '\0')
			{
				count++;
				break;
			}
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

static char  **memwords(const char *s, char c)
{
	int words;
	int i;
	int j;
	size_t start;
	char **strs;

	words = countwords(s, c);
	i = 0;
	j = 0;
	start = 0;
	strs = (char **) malloc(sizeof(char *) * words);
	if (strs == 0)
		return (0);
	while (i < words)
	{
		while (s[start] != c)
			start++;
		strs[i] = (char *) malloc(sizeof(char) * countletters(s, c, (start + 1)) + 1);
		if (strs[i] == 0)
			return (0);
		i++;
	}
	return (strs);
}

static char **insertwords(char **strs, const char *s, char c, int nword)
{
	int j;
	size_t start;
	size_t end;

	j = 0;
	start = 0;
	while (j < nword)
	{
		while ((s[start] != '\0') || (s[end] != '\0'))
		{
			while (((s[start] == c) && (s[start + 1] == c)) 
						|| ((s[start] == c) && (s[start - 1] == c)) || (s[start] == c))
			{
				start++;
				if ((s[start] == '\0'))
					return (strs);
			}
			end = countletters(s, c, start) + start;
			strs[j++] = ft_substr(s, start, countletters(s, c, start));
			if (j == nword)
				return (strs);
			start = end;
		}
	}
	return (strs);
}