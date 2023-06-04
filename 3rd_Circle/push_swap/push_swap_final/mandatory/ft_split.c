/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:00:30 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/05 13:57:02 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countwords(char const *s, char c)
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
				break ;
		}
	}
	return (count);
}

static int	countletters(const char *s, char c, size_t start)
{
	int	count;

	count = 0;
	while (s[start] != '\0')
	{
		if (s[start] == c)
			break ;
		count++;
		start++;
	}
	return (count);
}

static char	**insertwords(char **strs, const char *s, char c, int wordcount)
{
	int		j;
	size_t	start;

	j = 0;
	start = 0;
	while (j < wordcount)
	{
		while (((s[start] == c) && (s[start + 1] == c))
			|| ((s[start] == c) && (s[start - 1] == c)) || (s[start] == c))
		{
			start++;
			if ((s[start] == '\0'))
				return (strs);
		}
		strs[j] = ft_substr((char *)s, start, countletters(s, c, start));
		j++;
		start += countletters(s, c, start);
	}
	return (strs);
}

static char	**ft_singlevalues(void)
{
	char	**splitted;

	splitted = (char **) malloc (sizeof(char *));
	splitted[0] = 0;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (ft_singlevalues());
	words = countwords(s, c);
	strs = (char **) ft_calloc((words + 1), sizeof(char *));
	if (strs == 0)
		return (0);
	insertwords(strs, s, c, words);
	return (strs);
}
