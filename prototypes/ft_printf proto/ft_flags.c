/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:23 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/12 13:20:24 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_genflag(void)
{
	t_flags	*flag;

	flag = (t_flags *) malloc(sizeof(t_flags));
	ft_resetflag(flag);
	return (flag);
}

int	ft_resetflag(t_flags *flag)
{
	flag -> type = 0;
	flag -> signflag = 0;
	flag -> spaceflag = 0;
	flag -> hashflag = 0;
	return (0);
}

/* ft_countformat - i = position of % */
int	ft_countformat(char *str, int i)
{
	int	n;
	int	percentcount;

	n = i;
	percentcount = 0;
	if (str[n] == '%' && str[n + 1] == '%')
		return (1);
	while ((str[n] == '%') || (str[n] == '#')
		|| (str[n] == '+') || (str[n] == ' '))
		n++;
	return (n - i);
}
