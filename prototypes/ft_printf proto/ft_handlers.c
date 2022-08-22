#include "ft_printf.h"

int	ft_mainhandler(t_flags *flag, va_list args)
{
	int	printedcount;

	printedcount = 0;
	if (flag -> type == 1)
		printedcount = ft_charhandler(flag, args);
	else if (flag -> type == 2)
		printedcount = ft_strhandler(flag, args);
	else if (flag -> type == 3)
		printedcount = ft_ptrhandler(flag, args);
	else if (flag -> type == 4 || flag -> type == 5)
		printedcount = ft_inthandler(flag, args);
	else if (flag -> type == 6 || flag -> type == 7)
		printedcount = ft_hexhandler(flag, args);
	else if (flag -> type == 8)
		printedcount = ft_percenthandler(flag, args);
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

	ft_printptr((uintptr_t) va_arg(args, uintptr_t));
	return (rtv);
}

int	ft_undechandler(t_flags *flag, va_list args)
{
	int	rtv;

	rtv = ft_printundec((unsigned int) va_arg(args, unsigned int));
	return (rtv);
}

int ft_hexhandler(t_flags *flag, va_list args)
{
	int	rtv;

	if (flag -> type == 7)
		rtv = ft_printhex((int) va_arg(args, int), "0123456789abcdef");
	if (flag -> type == 8)
		rtv = ft_printhex((int) va_arg(args, int), "0123456789ABCDEF");
	
}

int	ft_percenthandler(t_flags *flag, va_list args)
{

}


//to do
// find a way to count length of ptr and hexa printed
// test whole thing and fix bugs