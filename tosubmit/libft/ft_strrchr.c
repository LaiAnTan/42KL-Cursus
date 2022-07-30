/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:33:20 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/30 18:16:50 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*str;

	str = (char *) s;
	n = ft_strlen(str);
	if (!str)
		return (0);
	while (n >= 0)
	{
		if (str[n] == (unsigned char) c)
			return (&str[n]);
		n--;
	}
	if (c == '\0')
		return (&str[n]);
	return (0);
}
