/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:34:42 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/21 15:53:28 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	if (len == 0)
		return (ft_strdup(""));
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
		if (*s1 == '\0')
			return (ft_strdup(""));
	}
	while (len && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(s1, 0, (len + 1)));
}
