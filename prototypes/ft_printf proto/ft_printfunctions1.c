#include "libftprintf.h"

void	ft_printchr(char c)
{
	write(1, &c, 1);
}
void	ft_printstr(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		ft_printchr(s[i]);
		i++;
	}
}

void	ft_printptr(uintptr_t n)
{
	char *b16 = "0123456789abcdef";
	if (n >= 16)
		ft_printptr(n / 16);
	ft_printchr(b16[n % 16]);
}

void	ft_printdec(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	while (str[i] != '\0')
		write(1, &str[i], 1);
	free(str);
}
void	ft_printint(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	while (str[i] != '\0')
		write(1, &str[i], 1);
	free(str);
}

// ft_printundec
// ft_printhexlow
// ft_printhexup
// ft_printpercent