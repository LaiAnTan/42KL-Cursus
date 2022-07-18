/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:59 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:54:22 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	int		i;
	char	*src;
	char	*dst;

	i = 0;
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
