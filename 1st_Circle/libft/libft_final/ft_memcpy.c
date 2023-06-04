/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:59 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/21 16:45:00 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	int		i;
	char	*src;
	char	*dst;

	i = 0;
	if (!s || !d)
		return (0);
	src = (char *) s;
	dst = (char *) d;
	while (n)
	{
		dst[i] = src[i];
		n--;
		i++;
	}
	return (d);
}
