/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:33:16 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:33:17 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int check(char *big, char *little, size_t j, size_t size);

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t j;
	size_t size;
	char *s1;
	char *s2;

	j = 0;
	size = len;
	if (big && little && len)
	{
		s1 = (char *) big;
		s2 = (char *) little;
		if (!ft_strlen(s2))
			return (s1);
		while ((len) && (s1[j] != '\0'))
		{
			if(s2[0] == s1[j])
			{
				if (check(s1, s2, j, size))
					return (&s1[j]);
			}
			j++;
			len--;
		}
	}
	return (0);
}

int check(char *big, char *little, size_t j, size_t size)
{
	size_t i;

	i = 0;
	while ((little[i] != '\0') && (j < size))
	{
		if(little[i] == big[j])
		{
			i++;
			j++;
		}
		else
			break;
	}
	if(i == ft_strlen(little))
		return (1);
	else
		return (0);
}