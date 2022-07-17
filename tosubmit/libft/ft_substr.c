/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:14:55 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/17 16:32:07 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
	size_t  i;

    i = -1;
    str = (char *) malloc(sizeof(char) * len + 1);
    if (str == 0)
        return (0);
    while (++i < len && s[start])
    {
        str[i] = s[start];
        start++;
    }
	str[i] = '\0';
    return (str);
}

