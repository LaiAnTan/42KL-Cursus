#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	va_list arglist;
	char *str;

	str = createstring(format, arglist);
}

// a - print and check for % while printing
// b - look through the string and substitute % then print everything in 1 go

char *createstring(const char *format, va_list arglist)
{

}

char *countvarsize(char datatype, va_list arglist)
{
	int size;

	if(datatype = 'c')
		size = sizeof(va_arg(arglist, char));
	else if (datatype = 's')
		size = sizeof(va_arg(arglist, char *));
	else if (datatype = 'd')
		size = sizeof(va_arg(arglist, int));
	else if (datatype = 'p')
		size = sizeof(va_arg(arglist, void *));
	else if (datatype = '')




}
