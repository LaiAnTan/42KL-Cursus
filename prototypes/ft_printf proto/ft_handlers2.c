/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:36 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/15 15:23:54 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_undechandler(t_flags *flag, va_list args)
{
	int	rtv;

	rtv = ft_printundec(flag, va_arg(args, unsigned int));
	return (rtv);
}

int	ft_hexhandler(t_flags *flag, va_list args)
{
	int	num;
	int	count;

	num = (int) va_arg(args, int);
	count = 0;
	if (flag -> hashflag && num != 0)
	{
		if (flag -> hashflag == 1 && flag -> type == 7)
			write(1, "0x", 2);
		else if (flag -> hashflag == 1 && flag -> type == 8)
			write(1, "0X", 2);
		count += 2;
	}
	if (flag -> type == 7)
		ft_printhex(num, "0123456789abcdef");
	else if (flag -> type == 8)
		ft_printhex(num, "0123456789ABCDEF");
	return (ft_counthex(num) + count);
}

int	ft_percenthandler(void)
{
	return (ft_printchr('%'));
}
