#include "ft_printf.h"

int	ft_mainhandler(t_flags *flag, char *str, int index, va_list args)
{
	int	printedcount;

	printedcount = 0;
	if (flag -> type == 1)
		printedcount = ft_charhandler();
	else if (flag -> type == 2)
		printedcount = ft_strhandler();
	else if (flag -> type == 3)

	else if (flag -> type == 4)

	else if (flag -> type == 5)

	else if (flag -> type == 6)

	else if (flag -> type == 7)

	else if (flag -> type == 8)

	else if (flag -> type == 9)

	return (printedcount);
}

int	ft_charhandler(t_flags *flag)