/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/07/07 16:31:21 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:40:46 by tlai-an          ###   ########.fr       */
=======
/*   Created: 2022/07/17 16:13:24 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/17 16:38:05 by tlai-an          ###   ########.fr       */
>>>>>>> d78196510a6fbdf74318e16d89400981779984ba
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (!nmemb || !size)
		return (0);
	str = malloc(nmemb * size);
	if (!str)
		return (0);
	ft_bzero(str, (nmemb * size - 1));
	return (str);
}
