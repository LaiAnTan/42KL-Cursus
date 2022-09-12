/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:32 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/12 13:20:33 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mainhandler(t_flags *flag, va_list args)
{
	int	printedcount;

	printedcount = 0;
	printedcount += ft_printflags(flag);
	if (flag -> type == 1)
		printedcount += ft_charhandler(args);
	else if (flag -> type == 2)
		printedcount += ft_strhandler(args);
	else if (flag -> type == 3)
		printedcount += ft_ptrhandler(args);
	else if (flag -> type == 4 || flag -> type == 5)
		printedcount += ft_inthandler(flag, args);
	else if (flag -> type == 6)
		printedcount += ft_undechandler(flag, args);
	else if (flag -> type == 7 || flag -> type == 8)
		printedcount += ft_hexhandler(flag, args);
	else if (flag -> type == 9)
		printedcount += ft_percenthandler();
	return (printedcount);
}

int	ft_charhandler(va_list args)
{
	int		rtv;

	rtv = 0;
	rtv += ft_printchr((char) va_arg(args, int));
	return (rtv);
}

int ft_strhandler(va_list args)
{
	int	rtv;

	rtv = ft_printstr((char *) va_arg(args, char *));
	return (rtv);
}

int	ft_inthandler(t_flags *flag, va_list args)
{
	int		rtv;

	rtv = ft_printint(flag, (int) va_arg(args, int));
	return (rtv);
}

int	ft_ptrhandler(va_list args)
{
	int	rtv;
	uintptr_t	ptr;

	ptr = (uintptr_t) va_arg(args, uintptr_t);
	ft_printptr(ptr, "0123456789abcdef");
	return (ft_counthex(ptr));
}

