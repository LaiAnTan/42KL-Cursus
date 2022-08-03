/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:01:06 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/24 10:37:55 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**setarray(char *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && ((s[i + 1] == c) || s[i + 1] == '\0'))
			j++;
		i++;
	}
	arr = (char **)ft_calloc(j + 1, sizeof(char *));
	if (!arr)
		return (0);
	return (arr);
}

static char	*callocforpointer(char **arr, int m, int j)
{
	arr[m] = (char *)ft_calloc(j + 1, sizeof(char));
	if (!arr[m])
	{
		while (m > 0)
			free(arr[--m]);
		free(arr);
		return (ft_strdup("error"));
	}
	return (arr[m]);
}

static int	setpointer(char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	m = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
			j++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			arr[m] = callocforpointer(arr, m, j);
			if (ft_strncmp(arr[m], "error", 5) == 0)
			{
				free(arr[m]);
				return (0);
			}
			m++;
			j = 0;
		}
		i++;
	}
	return (1);
}

static void	copy(char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	m = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			arr[m][j] = s[i];
			j++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			m++;
			j = 0;
		}
		i++;
	}
	arr[m] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	arr = setarray(str, c);
	if (!arr)
		return (0);
	if (setpointer(str, c, arr) == 0)
		return (0);
	copy(str, c, arr);
	return (arr);
}
