#include "ft_printf.h"

static int ft_foundpercent(char *s, int index, va_list args);
static int ft_validflag(t_flags *flag, char *str, int index, va_list args);

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
			check = ft_foundpercent((char *)format, i + 1, arglist);
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



static int ft_foundpercent(char *s, int index, va_list args)
{
	t_flags	*flag;
	int		i;


	flag = ft_genflag();
	i = ft_validflag(flag, s, index, args);
	free(flag);
	return (i);
}

static int ft_validflag(t_flags *flag, char *str, int index, va_list args)
{
	int initial;

	initial = index;
	if (str[index] == '#')
	{
		flag -> hashflag = 1;
		index++;
	}
	while (str[index] == ' ' || str[index] == '+')
	{
		if (str[index] == '+')
		{
			flag -> signflag = 1;
			break;
		}
		else
			flag -> spaceflag = 1;
		index++;
	}
	if (str[index] == 'c')
		flag -> type = 'c';
	else if (str[index] == 's')
		flag -> type = 's';
	else if (str[index] == 'p')
		flag -> type = 'p';
	else if (str[index] == 'd')
		flag -> type = 'd';
	else if (str[index] == 'i')
		flag -> type = 'i';
	else if (str[index] == 'u')
		flag -> type = 'u';
	else if (str[index] == 'x')
		flag -> type = 'x';
	else if (str[index] == 'X')
		flag -> type = 'X';
	else if (str[index] == '%')
		flag -> type = '%';
	else
		return (initial - index);
	return (index - initial);
}

//	flags: +, ,#
//	conversion specifiers: c,s,p,d,i,u,x,X,%

//handlers for all datatypes + none
//handlers print and count printed