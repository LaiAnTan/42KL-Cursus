/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:00:30 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/22 14:01:38 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c);
static int	countletters(const char *s, char c, size_t start);
static char	**insertwords(char **strs, const char *s, char c);

static char	**ft_singlevalues(void)
{
	char	**splitted;

	splitted = (char **) malloc (1 * sizeof(char *));
	splitted[0] = 0;
	return (splitted);
}

char 	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (ft_singlevalues());
	words = countwords(s, c);
	strs = (char **) malloc(sizeof(char *) * (words + 1));
	if (strs == 0)
		return (0);
	insertwords(strs, s, c);
	strs[words] = 0;
	return (strs);
}

static int countwords(char const *s, char c)
{
	int	count;
	int	i;

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

static char **insertwords(char **strs, const char *s, char c)
{
	int j;
	size_t start;

	j = 0;
	start = 0;
	while ((s[start] != '\0'))
	{
		while (((s[start] == c) && (s[start + 1] == c)) || ((s[start] == c) && (s[start - 1] == c)) || (s[start] == c))
		{
			start++;
			if ((s[start] == '\0'))
				return (strs);
		}
		strs[j] = ft_substr(s, start, countletters(s, c, start));
		j++;
		start += countletters(s, c, start);
	}
	return (strs);
}
