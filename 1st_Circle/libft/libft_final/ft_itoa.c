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

static int	countchar(int n);

char	*ft_itoa(int n)
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
	if (n < 0)
	{
		str[0] = '-';
		num *= -1;
		i = 0;
	}
	while (--digit != i)
	{
		str[digit] = (char)((num % 10) + '0');
		num /= 10;
	}
	return (str);
}

static int	countchar(int n)
{
	int				count;
	unsigned int	num;

	count = 0;
	num = n;
	if (n < 0)
	{
		count++;
		num = -num;
	}
	while (num >= 0)
	{
		num = num / 10;
		count++;
		if (num == 0)
			break ;
	}
	return (count);
}
