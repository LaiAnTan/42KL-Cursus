/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:32:38 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 17:00:08 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		n;
	char	*str;

	n = 0;
	str = (char *) s;
	if (!str)
		return (0);
	while (str[n] != '\0')
	{
		if (str[n] == c)
		{
			return (&str[n]);
		}
		n++;
	}
	if (c == '\0')
		return (&str[n]);
	return (0);
}
