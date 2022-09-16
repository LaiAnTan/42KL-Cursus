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
	str = ft_itoa(n);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}

int	ft_printundec(t_flags *flag, unsigned int n)
{
	int		i;
	int		rtv;
	char	*str;

	i = 0;
	str = ft_unitoa(n);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}

int	ft_printflags(t_flags *flag)
{
	if (flag -> spaceflag == 1)
	{
		write(1, " ", 1);
		return (1);
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
