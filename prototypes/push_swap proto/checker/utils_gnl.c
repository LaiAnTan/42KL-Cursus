/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:19:47 by tlai-an           #+#    #+#             */
/*   Updated: 2022/11/16 18:23:52 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_append(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1 != NULL)
	{
		while (s1[j] != '\0')
			temp[i++] = s1[j++];
	}
	if (s2 != NULL)
	{
		while (*s2 != '\0')
			temp[i++] = *s2++;
	}
	temp[i] = '\0';
	free(s1);
	return (temp);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str)
		return (NULL);
	dest = (char *) malloc (sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	free(str);
	return (dest);
}
