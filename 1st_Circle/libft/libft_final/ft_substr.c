/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:33:28 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/30 19:13:12 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = -1;
	if (!s)
		return (0);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s) || !len)
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
