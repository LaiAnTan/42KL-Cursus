/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/07/07 16:31:52 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:51:48 by tlai-an          ###   ########.fr       */
=======
/*   Created: 2022/07/17 16:13:51 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/17 16:26:12 by tlai-an          ###   ########.fr       */
>>>>>>> d78196510a6fbdf74318e16d89400981779984ba
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		m;
<<<<<<< HEAD
	char	*occ;
	char	*src;

	m = 0;
	src = (char *) s;
=======
	char 	*src;

	m = 0;
	src = (char *) s;	
>>>>>>> d78196510a6fbdf74318e16d89400981779984ba
	while (n)
	{
		if (src[m] == c)
			return (&src[m]);
		n--;
		m++;
	}
	return (0);
}
