/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:42:39 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 11:46:30 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	overflow_check(int val, char lastdigit, int sign)
{
	if (val <= 214748364)
		return (0);
	else
	{
		if (val >= 214748364 && ((lastdigit > '7' && sign == 1)
				|| (lastdigit > '8' && sign == -1)))
			return (-1);
		return (0);
	}
}

int	ft_atoi(const char *s)
{
	int		sign;
	long	rtval;
	char	*str;

	sign = 1;
	rtval = 0;
	str = (char *) s;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (-1);
		if (overflow_check(rtval, *str, sign) == -1)
			return (-1);
		rtval = (rtval * 10) + (*str - '0');
		str++;
	}
	return ((int)(rtval * sign));
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	is_present(char *str, char c)
{
	int		n;

	n = ft_strlen(str);
	if (!str)
		return (0);
	while (n >= 0)
	{
		if (str[n] == c)
			return (1);
		n--;
	}
	return (0);
}
