#include "ft_printf.h"

int	ft_mainhandler(t_flags *flag, va_list args)
{
	int	printedcount;

	printedcount = 0;
	if (flag -> type == 1)
		printedcount = ft_charhandler(flag, args);
	return (printedcount);
}

int	ft_charhandler(t_flags *flag, va_list args)
{
	int		rtv;

	rtv = 0;
	rtv += ft_printchr((char) va_arg(args, int));
	return (rtv);
}

int	ft_inthandler(t_flags *flag, va_list args)
{
	int		rtv;
	int		i;

	rtv = 0;
	i = va_arg(args, int);
	if (flag -> signflag == 1)
	{
		if (i > 0)
		write(1, " ", 1);
		rtv++;
	}
	if (flag -> spaceflag == 1)
	{
		write(1, " ", 1);
		rtv++;
	}
	ft_printint(i);
	return (rtv);
}

void	ft_printflags(t_flags *flag)
{
	if (flag -> spaceflag == 1)
		write(1, " ", 1);
	if (flag -> hashflag == 1 && type == 7)
		write(1, "0x", 2);
	if (flag -> hashflag == 1 && type == 8)
		write(1, "0X", 2);
}

void	ft_printsignflag(t_flags *flag, int num)
{
	if (flag -> signflag == 1)
	{
		if (num >= 0)
			write(1, "+", 1);
	}
}


