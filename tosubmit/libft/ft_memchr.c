/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:52 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:51:48 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		m;
	char	*occ;
	char	*src;

	m = 0;
	src = (char *) s;
	while (n)
	{
		if (src[m] == c)
		{
			occ = &src[m];
			return (occ);
		}
		n--;
		m++;
	}
	return (0);
}
