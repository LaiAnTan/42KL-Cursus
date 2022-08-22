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

int	ft_printflags(t_flags *flag)
{
	int	i;

	i = 1;
	if (flag -> spaceflag == 1)
		write(1, " ", 1);
	if (flag -> hashflag)
		i = 2;
	if (flag -> hashflag == 1 && type == 7)
		write(1, "0x", 2);
	else if (flag -> hashflag == 1 && type == 8)
		write(1, "0X", 2);
	return (i);
}

int	ft_printsignflag(t_flags *flag, int num)
{
	if (flag -> signflag == 1)
	{
		if (num >= 0)
		{
			write(1, "+", 1);
			return (1);
		}
	}
	return (0);
}