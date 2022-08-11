#include "ft_printf.h"

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

//dec same as int

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

void	ft_printhex(int n, char* b16)
{
	if (n >= 16)
		ft_printhex(n / 16, b16);
	ft_printchr(b16[n % 16]);
}

// char *b16 = "0123456789abcdef" or "0123456789ABCDEF"