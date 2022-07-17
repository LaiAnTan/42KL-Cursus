/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:14:50 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/17 16:31:02 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (s1 && s2 && n)
	{
		str1 = (unsigned char *) s1;
		str2 = (unsigned char *) s2;
		while (n > i)
		{
			if (str1[i] > str2[i])
				return (1);
			else if (str1[i] < str2[i])
				return(-1);
			else
				i++;

		}
	}
	return (0);
}