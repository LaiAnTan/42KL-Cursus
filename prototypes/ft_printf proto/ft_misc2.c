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
