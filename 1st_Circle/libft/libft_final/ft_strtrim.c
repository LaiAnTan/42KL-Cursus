/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:34:42 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/30 18:28:20 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		begin;
	int		end;
	char	*trim;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	begin = -1;
	end = len;
	while (check(set, s1[++begin]))
		len--;
	if (begin != end)
	{
		while (check(set, s1[--end]))
			len--;
	}
	else
		return (ft_strdup(""));
	trim = ft_substr(s1, begin, len);
	return (trim);
}
