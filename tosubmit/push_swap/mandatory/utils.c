/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:36:37 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/04 15:49:52 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overflow_check(int val, char lastdigit, int sign)
{
	if (val <= 214748364)
	{
		if (val == 214748364)
		{
			if ((lastdigit <= '7' && sign == 1)
				|| (lastdigit <= '8' && sign == -1))
				return (0);
		}
		else
			return (0);
	}
	return (-1);
}

int	ft_atoi(const char *s, t_stack *stack)
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
			return (error(1, stack));
		if (overflow_check(rtval, *str, sign) == -1)
			return (error(2, stack));
		rtval = (rtval * 10) + (*str - '0');
		str++;
	}
	return ((int)(rtval * sign));
}

int	*ft_intarrdup(int *arr, int size)
{
	int		i;
	int		*dest;

	i = 0;
	dest = (int *) malloc(sizeof(int) * size);
	if (dest == 0)
		return (0);
	while (i < size)
	{
		dest[i] = arr[i];
		i++;
	}
	return (dest);
}

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}
