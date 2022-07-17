/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:13:51 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/17 16:26:12 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		m;
	char 	*src;

	m = 0;
	src = (char *) s;	
	while (n)
	{
		if (src[m] == c)
			return (&src[m]);
		n--;
		m++;
	}
	return (0);
}