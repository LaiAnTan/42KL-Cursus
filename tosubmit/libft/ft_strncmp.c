/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:33:13 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/19 15:03:04 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
			if (str1[i] == '\0' || str2[i] == '\0')
				return (0);
			else if (str1[i] > str2[i])
				return (1);
			else if (str1[i] < str2[i])
				return (-1);
			else
				i++;
		}
	}
	return (0);
}
