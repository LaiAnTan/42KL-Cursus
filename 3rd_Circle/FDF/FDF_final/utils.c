/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:42:59 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 11:47:47 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (!size || !nmemb)
	{
		str = malloc(0);
		return (str);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (0);
	ft_bzero(str, (nmemb * size));
	return (str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str)
		return (0);
	dest = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == 0)
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		dest[i] = '\0';
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = -1;
	if (!s)
		return (0);
	if (len >= ft_strlen((char *) s))
		len = ft_strlen((char *) s);
	if (start >= ft_strlen((char *) s) || !len)
		return (ft_strdup(""));
	str = (char *) ft_calloc((len + 1), sizeof(char));
	if (str == 0)
		return (0);
	while (++i < len && s[start] != '\0')
	{
		str[i] = s[start];
		start++;
	}
	return (str);
}
