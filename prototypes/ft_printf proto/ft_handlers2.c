/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:36 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/12 13:27:15 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_undechandler(t_flags *flag, va_list args)
{
	int	rtv;

	rtv = ft_printundec(flag, (unsigned int) va_arg(args, unsigned int));
	return (rtv);
}

int	ft_hexhandler(t_flags *flag, va_list args)
{
	int	rtv;
	int	num;

	num = (int) va_arg(args, int);
	if (flag -> type == 7)
	{
		ft_printhex(num, "0123456789abcdef");
		return (ft_counthex(num));
	}
	else if (flag -> type == 8)
	{
		ft_printhex(num, "0123456789ABCDEF");
		return (ft_counthex(num));
	}
}

int	ft_percenthandler(void)
{
	return (ft_printchr('%'));
}
