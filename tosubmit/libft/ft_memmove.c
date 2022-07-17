/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:13:58 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/17 16:15:36 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *d, const void *s, size_t n)
{
	char * src;
	char * dest;
	size_t i;

	src = (char *) s;
	dest = (char *) d;
	i = 0;
	if (dest > src)
	{
		while (n-- > 0)
			dest[n] = src[n];
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (d);
}