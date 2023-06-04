/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:52 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/30 18:30:44 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		m;
	char	*src;

	m = 0;
	src = (char *) s;
	while (n)
	{
		if (src[m] == (char) c)
			return (&src[m]);
		n--;
		m++;
	}
	return (0);
}
