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
	while(s[++i] != '\0')
	{
		if(s[i] == '%')
		{
			check = ft_foundpercent(s, i, arglist);
		}
		else
		{
			ft_printchr(s[i]);
			++pcount;
		}
	}
	return (pcount);
}

//print and check for % while printing

//	flags: +, ,#
//	conversion specifiers: c,s,p,d,i,u,x,X,%

static ft_foundpercent(char *s, int n, va_list args)
{
	t_flags *flag;


	flag = ft_genflag();

	free(flag);
}




//save flags in struct???
//handlers for all datatypes + none
//handlers print and count printed 
//yes