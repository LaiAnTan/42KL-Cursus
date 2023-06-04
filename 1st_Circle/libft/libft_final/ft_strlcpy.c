/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:33:03 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/19 15:02:25 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	char	*s;

	n = 0;
	s = (char *) src;
	if (size)
	{
		while ((s[n] != '\0') && (n < size - 1))
		{
			dst[n] = s[n];
			n++;
		}
		dst[n] = '\0';
	}
	return (ft_strlen(s));
}
