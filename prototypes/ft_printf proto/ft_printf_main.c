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
	i = ft_assignformat(flag, s, index);
	free(flag);
	return (i);
}

static int ft_assignformat(t_flags *flag, char *str, int index) // index = pos of %
{
	if (ft_assignflag(flag, str, index + 1))
	{

	}
}

static int ft_validflag(char *str, int n) // n = pos of char after %
{
	int	hash;
	int sign;

	hash = 0;
	sign = 0;
	while ((str[n] == '#') || (str[n] == '+') || (str[n] == ' '))
	{
		if (str[n] == '#')
			hash++;
		while (str[n] == '+' || str[n] == ' ')
		{
			if (str[n] == '+' && !hash)
				sign++;
			else if ((str[n] == '+' || str[n] == ' ') && hash)
				return (0);
			else if (sign > 1)
				return (0);
			n++;
		}
	}
	return (1);
}

static void ft_assignflag(t_flags *flag, char *str, int n) //n = pos of char after %
{
	if(ft_validflag(str, n))
	{
		if(str[n] == '#')
		{
			flag -> hashflag = 1;
			n++;
		}
		while ((str[n] == '+') || (str[n] == ' '))
		{
			if (str[n] == '+')
			{
				flag -> signflag = 1;
				flag -> spaceflag = 0;
				return (1);
			}
			else
				flag -> spaceflag = 1;
			i++;
		}
	}
	else
		return (0);
	return (1);
}

static int ft_assigntype(t_flags flag, char c)
{
	int	i;

	i = 1;
	if (c == 'c')
		flag -> type = 1;
	else if (c == 's')
		flag -> type = 2;
	else if (c == 'p')
		flag -> type = 3;
	else if (c == 'd')
		flag -> type = 4;
	else if (c == 'i')
		flag -> type = 5;
	else if (c == 'u')
		flag -> type = 6;
	else if (c == 'x')
		flag -> type = 7;
	else if (c == 'X')
		flag -> type = 8;
	else if (c == '%')
		flag -> type = 9;
	else
		i = 0;
	return (i);
}

//	flags: +, ,#
//	conversion specifiers: c,s,p,d,i,u,x,X,%

//handlers for all datatypes + none
//handlers print and count printed
