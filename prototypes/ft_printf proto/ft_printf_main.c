#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	arglist;
	int		i;
	int		check;
	int		pcount;

	i = -1;
	pcount = 0;
	va_start(arglist, format);
	while(format[++i] != '\0')
	{
		if(format[i] == '%')
		{
			check = ft_foundpercent((char *)format, i, arglist);
			if (!check)
			{
				pcount += ft_printchr(format[i]);
				continue ;
			}
			i--;
		}
		else
			pcount += ft_printchr(format[i]);
	}
	va_end(arglist);
	return (pcount);
}

//print and check for % while printing

static int ft_foundpercent(char *s, int index, va_list args) // index = pos of %
{
	t_flags	*flag;
	int		i;


	flag = ft_genflag();
	i = ft_assignformat(flag, s, index, args);
	free(flag);
	return (i);
}



//	flags: +, ,#
//	conversion specifiers: c,s,p,d,i,u,x,X,%

//handlers for all datatypes
//handlers print and count printed
