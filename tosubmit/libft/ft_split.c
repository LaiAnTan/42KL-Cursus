#include "libft.h"

static int 		countwords(char const *s, char c);
static int 		countletters(const char *s, char c, int start);
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
	printf("no of words: %d\n", count);
	return (count);
}

static int countletters(const char *s, char c, int start)
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
	printf("no of letters: %d\n", count);
	return (count);
}

static char  **memwords(const char *s, char c)
{
	int words;
	int i;
	int j;
	int start;
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
	printf("mem allocated\n");
	return (strs);
}

static char **insertwords(char **strs, const char *s, char c, int nword)
{
	int j;
	int start;
	int end;

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
				printf("start is now %d\n", start);
			}
			end = countletters(s, c, start) + start;
			printf("wordlen: %d\n", countletters(s, c, start));
			printf("end is now %d\n", end);
			strs[j++] = ft_substr(s, start, end);
			printf("substr\n");
			start = end;
			printf("start is now %d\n", start);
		}
	}
	return (strs);
}