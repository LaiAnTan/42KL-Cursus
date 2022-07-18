/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:04 by tlai-an           #+#    #+#             */
/*   Updated: 2022/07/07 16:38:37 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		n;
	int		sign;
	int		rtval;
	char	*str;

	n = 0;
	sign = 1;
	rtval = 0;
	str = (char *) s;
	while (str[n] == ' ' || (str[n] >= 9 && str[n] <= 13))
		++n;
	if (str[n] == '-')
	{
		n++;
		sign *= -1;
	}
	else if (str[n] == '+')
		n++;
	while (str[n] >= '0' && str[n] <= '9')
	{
		rtval = (rtval * 10) + (str[n] - '0');
		++n;
	}
	return (rtval * sign);
}
