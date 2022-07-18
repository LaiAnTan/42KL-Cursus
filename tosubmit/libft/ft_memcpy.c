/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/07/07 16:31:59 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:54:22 by tlai-an          ###   ########.fr       */
=======
/*   Created: 2022/07/17 16:13:56 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/17 16:27:07 by tlai-an          ###   ########.fr       */
>>>>>>> d78196510a6fbdf74318e16d89400981779984ba
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
<<<<<<< HEAD
	int		i;
	char	*src;
	char	*dst;
=======
	int i;
	char *src;
	char *dst;
>>>>>>> d78196510a6fbdf74318e16d89400981779984ba

	i = 0;
	src = (char *) s;
	dst = (char *) d;
	while (n)
	{
		dst[i] = src[i];
		n--;
		i++;
	}
	return (d);
}
