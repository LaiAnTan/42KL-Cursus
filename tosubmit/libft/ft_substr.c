/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:33:28 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/22 16:13:54 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = -1;
	if (start > ft_strlen(s))
		return (0);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	while (++i < len && s[start] != '\0')
	{
		str[i] = s[start];
		start++;
	}
	str[i] = '\0';
	return (str);
}
