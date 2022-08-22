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

void	ft_printptr(uintptr_t n)
{
	char *b16; 
	
	b16 = "0123456789abcdef";
	if (n >= 16)
		ft_printptr(n / 16);
	ft_printchr(b16[n % 16]);
}
