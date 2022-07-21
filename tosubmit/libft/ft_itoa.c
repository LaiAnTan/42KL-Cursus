/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:49 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:50:44 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countchar(int n);

char	*ft_itoa(int n)
{
	int				i;
	int				digit;
	unsigned int	num;
	char			*str;

	i = countchar(n);
	num = n;
	if (n == 0)
		i++;
	str = (char *) malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[i--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		digit = num % 10;
		num = num / 10;
		str[i--] = digit + '0';
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
