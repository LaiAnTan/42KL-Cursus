/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:32:59 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/19 14:58:28 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t size)
{
	size_t	n;
	size_t	dlen;
	size_t	slen;
	int		m;
	char	*src;

	dlen = ft_strlen(d);
	slen = ft_strlen(s);
	n = dlen;
	m = 0;
	src = (char *) s;
	if (size == 0 || dlen > size)
		return (size + slen);
	while ((n < size - 1) && (src[m] != '\0'))
	{
		d[n] = src[m];
		n++;
		m++;
	}
	d[n] = '\0';
	return (dlen + slen);
}
