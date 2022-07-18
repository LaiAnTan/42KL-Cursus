/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:56 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:53:05 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (s1 && s2 && n)
	{
		str1 = (char unsigned *) s1;
		str2 = (char unsigned *) s2;
		while (i < n)
		{
			if (str1[i] > str2[i])
				return (1);
			else if (str1[i] < str2[i])
				return (-1);
			i++;
		}
	}
	return (0);
}
