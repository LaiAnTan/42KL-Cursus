#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	va_list	arglist;
	int		i;

	ft_striter(format, i); //strchr to find % (?)
}

//print and check for % while printing


char *ft_striter(const char *format, int startindex) // put results in array and return 
{
	int		i;
	char	*s;
	char	*result;

	if(!format)
		return (0);
	i = startindex;
	s = *format;
	if (s[i] == '%' && s[i + 1] != '\0')
	{
		++i;
		if (s[i] == '#')
			++i;
		if (s[i] == '+' || s[i] == ' ')
			++i;
		
		if (s[i] != 'c' || s[i] != 's' || s[i] != 'p' || s[i] != 'd' || 
				s[i] != 'i' || s[i] != 'u' || s[i] != 'x' || s[i] != 'X' || 
				s[i] != '%')
			i++;

		
	}
}

//	flags: +, ,#
//	conversion specifiers: c,s,p,d,i,u,x,X,%
