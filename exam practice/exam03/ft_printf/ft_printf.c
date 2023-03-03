#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr(char *s)
{
	int i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	return (i);
}

void	putnbr(long long int nbr, int base, int *count)
{
	char *b = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		++*count;
	}
	if (nbr >= base)
		putnbr(nbr / base, base, count);
	*count += write(1, &b[nbr % base], 1);
}

int	ft_printf(const char *s, ...)
{
	int	i = 0;
	int	rv = 0;
	va_list	args;

	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			if (s[i + 1] == 's')
				rv += putstr(va_arg(args, char *));
			else if (s[i + 1] == 'd')
				putnbr((long long int)va_arg(args, int), 10, &rv);
			else if (s[i + 1] == 'x')
				putnbr((long long int)va_arg(args, int), 16, &rv);
			else
			{
				rv += ft_putchar('%');
				rv += ft_putchar(s[i]);
			}
			i += 2;
		}
		else
		{
			rv += ft_putchar(s[i]);
			i++;
		}
		
	}
	va_end(args);
	return (rv);
}


#include <stdio.h>

int main(void)
{
	printf("%d\n", printf("%xehehehhe\n", 69));

	printf("%d ", ft_printf("%xehehehhe\n", 69));
}