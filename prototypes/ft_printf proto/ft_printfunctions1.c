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

int	ft_printptr(int count, uintptr_t n, char *b16)
{
	if (n >= 16)
		ft_printptr(count + 1, n / 16, "0123456789abcdef");
	ft_printchr(b16[n % 16]);
	return (count + 1);
}
