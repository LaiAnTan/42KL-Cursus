#include "ft_printf.h"

int	ft_printchr(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t ft_printstr(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		ft_printchr(s[i]);
		i++;
	}
	return (ft_strlen(s));
}

void	ft_printptr(uintptr_t n, char *b16)
{
	if (n >= 16)
		ft_printptr(n / 16, b16);
	ft_printchr(b16[n % 16]);
}

void	ft_printhex(int n, char* b16)
{
	if (n >= 16)
		ft_printhex(n / 16, b16);
	ft_printchr(b16[n % 16]);
}

