#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	va_list	arglist;
	int		i;

	ft_striter(format, i); //strchr to find % (?)
}

//print and check for % while printing


char *ft_striter(const char *format, int index) // put results in array and return 
{
	char *result;

	if(!format[index])
		return (0);
	if (format[index] == '%' && format[index + 1] != '\0')
	{

	}
}

//	flags: +, ,#
//	conversion specifiers: c,s,p,d,i,u,x,X,%
