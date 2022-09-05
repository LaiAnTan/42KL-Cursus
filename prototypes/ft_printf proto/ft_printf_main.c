#include "ft_printf.h"

static int ft_foundpercent(char *s, int index, va_list args);

int ft_printf(const char *format, ...)
{
	va_list	arglist;
	int		i;
	int		pcount;

	i = -1;
	pcount = 0;
	va_start(arglist, format);
	while(format[++i] != '\0')
	{
		if(format[i] == '%')
		{
			pcount += ft_foundpercent((char *)format, i, arglist);
			i += ft_countflag((char *) format, i);
			printf("index: %d\n", i);
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
	printf("percent found\n");
	t_flags	*flag;
	int		i; //no of printed chars

	flag = ft_genflag();
	i = ft_assignformat(flag, s, index, args);
	free(flag);
	printf("format len: %d\n", i);
	return (i);
}



//	flags: +, ,#
//	conversion specifiers: c,s,p,d,i,u,x,X,%

//handlers for all datatypes
//handlers print and count printed
