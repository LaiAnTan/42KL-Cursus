/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:40 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/12 13:28:12 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countchar(int n)
{
	int	count;
	int	num;

	count = 0;
	num = n;
	if (n < 0)
		count++;
	while (1)
	{
		num = num / 10;
		count++;
		if (num == 0)
			break ;
	}
	return (count);
}

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_counthex(int n)
{
	int				count;
	unsigned int	num;

	count = 0;
	num = n;
	while (1)
	{
		num = num / 16;
		count++;
		if (num == 0)
			break ;
	}
	return (count);
}
