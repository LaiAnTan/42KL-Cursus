/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:32:32 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:59:33 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**freemem(char **strs);
static int		countwords(char const *s, char c);
static char		**insertwords(char **strs, const char *s, char c, int nword);
static char		**single(void);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	strs = 0;
	if (!s)
		return (0);
	if (s[0] == '\0')
		return (single());
	words = countwords(s, c);
	strs = (char **) malloc (sizeof(char *) * (words + 1));
	if (!strs)
		return (0);
	strs[words] = 0;
	if (!insertwords(strs, s, c, words))
		return (freemem(strs));
	return (strs);
}

static int	countwords(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	if (s[i] != c)
		count = 1;
	else
		count = 0;
	while (s[++i])
	{
		if ((s[i] != c) && (s[i - 1] == c))
			count++;
	}
	return (count);
}

static char	**insertwords(char **strs, const char *s, char c, int nword)
{
	int	i;
	int	j;
	int	start;
	int	let;

	i = -1;
	j = 0;
	start = 0;
	let = 0;
	while (j < nword)
	{
		if ((s[++i] == c || (s[i + 1] == '\0' && s[i] != c && ++let)) && let)
		{
			strs[j] = ft_substr(s, start, let);
			if (!strs[j++])
				return (0);
			start = i + 1;
			let = 0;
			continue ;
		}
		else if (s[i] == c && let == 0 && ++start)
			continue ;
		let++;
	}
	return (strs);
}

static char	**freemem(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
	return (0);
}

static char	**single(void)
{
	char	**strs;

	strs = (char **) malloc (sizeof(char *) * 1);
	strs[0] = 0;
	return (strs);
}
