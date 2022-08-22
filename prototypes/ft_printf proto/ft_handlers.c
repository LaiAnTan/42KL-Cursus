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

int ft_strhandler(t_flags *flag, va_list args)
{
	int	rtv;

	rtv = ft_printstr((char *) va_arg(args, char *));
	return (rtv);
}

int	ft_inthandler(t_flags *flag, va_list args)
{
	int		rtv;

	rtv = ft_printint((int) va_arg(args, int));
	return (rtv);
}

int	ft_ptrhandler(t_flags *flag, va_list args)
{
	int	rtv;
	int	i;

	rtv = 0;

	ft_printptr(uintptr_t n);
}


