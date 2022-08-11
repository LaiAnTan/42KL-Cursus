/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:49 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/30 17:51:14 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	countchar(unsigned int n);

char	*ft_unitoa(unsigned int n)
{
	int				digit;
	int				i;
	unsigned int	num;
	char			*str;

	digit = countchar(n);
	i = -1;
	str = (char *) malloc((digit + 1) * sizeof(char));
	if (!str)
		return (0);
	str[digit] = '\0';
	num = n;
	while (--digit != i)
	{
		str[digit] = (char)((num % 10) + '0');
		num /= 10;
	}
	return (str);
}

static int	countchar(unsigned int n)
{
	int				count;
	unsigned int	num;

	count = 0;
	num = n;
	while (num)
	{
		num = num / 10;
		count++;
		if (num == 0)
			break ;
	}
	return (count);
}
