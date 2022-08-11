#include "ft_printf.h"

void	ft_printundec(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_unitoa(n);
	while (str[i] != '\0')
		write(1, &str[i], 1);
	free(str);
}

void	ft_printhexlow(int n)
{
	char *b16 = "0123456789abcdef";
	if (n >= 16)
		ft_printhexlow(n / 16);
	ft_printchr(b16[n % 16]);
}

void	ft_printhexup(int n)
{
	char *b16 = "0123456789ABCDEF";
	if (n >= 16)
		ft_printhexup(n / 16);
	ft_printchr(b16[n % 16]);
}

void	ft_printpercent(void)
{
	write(1, '%', 1);
}