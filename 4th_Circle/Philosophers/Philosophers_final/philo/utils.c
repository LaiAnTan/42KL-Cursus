/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:03 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/19 17:02:08 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	overflow_check(int val, char lastdigit)
{
	if (val <= 214748364)
		return (0);
	else
	{
		if (val >= 214748364 && (lastdigit > '7'))
			return (-1);
		return (0);
	}
}

int	ft_atoi(const char *s)
{
	long	rtval;
	char	*str;

	rtval = 0;
	str = (char *) s;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
	{
		return (0);
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		if (overflow_check(rtval, *str) == -1)
			return (0);
		rtval = (rtval * 10) + (*str - '0');
		str++;
	}
	return ((int)(rtval));
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
	while (1)
	{
		num = num / 10;
		count++;
		if (num == 0)
			break ;
	}
	return (count);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
