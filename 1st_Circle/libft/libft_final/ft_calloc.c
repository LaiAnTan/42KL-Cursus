/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:21 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/30 17:51:22 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (!size || !nmemb)
	{
		str = malloc(0);
		return (str);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (0);
	ft_bzero(str, (nmemb * size));
	return (str);
}
