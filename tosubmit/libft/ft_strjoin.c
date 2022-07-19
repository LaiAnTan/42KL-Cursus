/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:32:54 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/19 14:56:26 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	sizetotal;
	size_t	size1;
	char	*str;

	i = 0;
	size1 = ft_strlen(s1);
	sizetotal = size1 + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (sizetotal + 1));
	ft_strlcat(str, s1, (size1 + 1));
	ft_strlcat(str, s2, (sizetotal + 1));
	return (str);
}
