#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	va_list	arglist;
	int		i;
	int		pcount;
	char	*s;
	char	*val; // 0 - how many characters printed; 1 - how long the format specifier is

	i = -1;
	pcount = 0;
	s = format;
	while(s[++i] != '\0')
	{
		if(s[i] == '%')
		{
			val = ft_something();
			pcount =  val[0];
			i += val[1];
		}
		else
		{
			ft_putchar(s[i]);
			++pcount;
		}
	}
	return (pcount);
}

//print and check for % while printing

//	flags: +, ,#
//	conversion specifiers: c,s,p,d,i,u,x,X,%
