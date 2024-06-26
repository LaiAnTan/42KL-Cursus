/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:21:12 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/15 15:21:32 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counthex(unsigned int n)
{
	int				count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_countptr(unsigned long long n)
{
	int				count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count);
}
