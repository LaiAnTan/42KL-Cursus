/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:52 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/12 13:44:34 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_foundpercent(char *s, int index, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	arglist;
	int		i;
	int		pcount;

	i = -1;
	pcount = 0;
	va_start(arglist, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			pcount += ft_foundpercent((char *)format, i, arglist);
			i += ft_countformat((char *) format, i);
		}
		else
			pcount += ft_printchr(format[i]);
	}
	va_end(arglist);
	return (pcount);
}

/* ft_foundpercent - index = position of % - i = number of printed characters */
static int	ft_foundpercent(char *s, int index, va_list args)
{
	t_flags	*flag;
	int		i;

	flag = ft_genflag();
	i = ft_assignformat(flag, s, index, args);
	free(flag);
	return (i);
}
