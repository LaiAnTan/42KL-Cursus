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
	s = (char *) format;
	while(s[++i] != '\0')
	{
		if(s[i] == '%')
		{
			ft_foundpercent(s, i + 1);
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

static ft_foundpercent(char *s, int n)
{

}




//save flags in struct???
//handlers for all datatypes + none
//handlers print and count printed 
//yes