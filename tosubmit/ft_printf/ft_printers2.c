/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:20:47 by tlai-an           #+#    #+#             */
/*   Updated: 2022/09/12 13:30:12 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(t_flags *flag, int n)
{
	int		i;
	int		rtv;
	char	*str;

	i = 0;
	rtv = ft_printsignflag(flag, n);
	str = ft_itoa(n);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i + rtv);
}

int	ft_printundec(t_flags *flag, unsigned int n)
{
	int		i;
	int		rtv;
	char	*str;

	i = 0;
	rtv = ft_printsignflag(flag, n);
	str = ft_unitoa(n);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i + rtv);
}

int	ft_printflags(t_flags *flag)
{
	if (flag -> spaceflag == 1)
	{
		write(1, " ", 1);
		return (1);
	}
	if (flag -> hashflag)
	{
		if (flag -> hashflag == 1 && flag -> type == 7)
			write(1, "0x", 2);
		else if (flag -> hashflag == 1 && flag -> type == 8)
			write(1, "0X", 2);
		return (2);
	}
	return (0);
}

int	ft_printsignflag(t_flags *flag, int num)
{
	if (flag -> signflag == 1)
	{
		if (num >= 0)
		{
			write(1, "+", 1);
			return (1);
		}
	}
	return (0);
}
