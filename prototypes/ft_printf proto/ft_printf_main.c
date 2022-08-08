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
			val = ft_something(s, i + 1);
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

static char *ft_something(char *str, int index)
{
	int ret[2];
	int	fcount;
	int	pcount;

	fcount = 0;
	if (str[index])
	{
		while (str[index])
		{

		}
	}
	ret[0] = pcount;
	ret[1] = fcount;
	return (ret);
}

void ft_printchr(char c)
{
	write(1, &c, 1);
}
void ft_printstr(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		ft_printchr(s[i]);
		i++;
	}
}

void ft_printptr(uintptr_t n)
{
	char *b16 = "0123456789abcdef";
	if (n >= 16)
		ft_printptr(n / 16);
	ft_printchar(b16[n % 16]);
}

// ft_printdec
// ft_printint
// ft_printundec
// ft_printhexlow
// ft_printhexup
// ft_printpercent


//save flags in struct???
//handlers for all datatypes + none
//handlers print and count printed 
//yes