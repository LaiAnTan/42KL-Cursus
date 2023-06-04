/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:27 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/12 13:24:06 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_validflag(char *str, int n);
static int	ft_assignflag(t_flags *flag, char *str, int n);
static int	ft_assigntype(t_flags *flag, char c);

/* ft_assignformat - index = position of % */
int	ft_assignformat(t_flags *flag, char *str, int index, va_list args)
{
	int	i;

	i = index;
	if (ft_assignflag(flag, str, i))
	{
		while (str[i] == ' ' || str[i] == '+' || str[i] == '#' || str[i] == '%')
		{
			if (ft_assigntype(flag, str[i + 1]) != 0)
			{
				return (ft_mainhandler(flag, args));
			}
			i++;
		}
	}
	return (0);
}

/* ft_validflag - n = position of % */
static int	ft_validflag(char *str, int n)
{
	int	hash;
	int	sign;

	hash = 0;
	sign = 0;
	n++;
	while ((str[n] == '#') || (str[n] == '+') || (str[n] == ' '))
	{
		if (str[n] == '#')
		{
			hash++;
			n++;
		}
		while (str[n] == '+' || str[n] == ' ')
		{
			if (str[n] == '+' && !hash)
				sign++;
			else if ((str[n] == '+' || str[n] == ' ') && hash)
				return (0);
			else if (sign > 1)
				return (0);
			n++;
		}
	}
	return (1);
}

/* ft_assignflag - n = position of % */
static int	ft_assignflag(t_flags *flag, char *str, int n)
{
	if (ft_validflag(str, n))
	{
		n++;
		if (str[n] == '#')
		{
			flag -> hashflag = 1;
			n++;
		}
		while ((str[n] == '+') || (str[n] == ' '))
		{
			if (str[n] == '+')
			{
				flag -> signflag = 1;
				flag -> spaceflag = 0;
				return (1);
			}
			else
				flag -> spaceflag = 1;
			n++;
		}
	}
	else
		return (ft_resetflag(flag));
	return (1);
}

static int	ft_assigntype(t_flags *flag, char c)
{
	int	i;

	i = 1;
	if (c == 'c')
		flag -> type = 1;
	else if (c == 's')
		flag -> type = 2;
	else if (c == 'p')
		flag -> type = 3;
	else if (c == 'd')
		flag -> type = 4;
	else if (c == 'i')
		flag -> type = 5;
	else if (c == 'u')
		flag -> type = 6;
	else if (c == 'x')
		flag -> type = 7;
	else if (c == 'X')
		flag -> type = 8;
	else if (c == '%')
		flag -> type = 9;
	else
		i = 0;
	return (i);
}
