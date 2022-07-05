#include "libft.h"

static int countdigit(int n);

char *ft_itoa(int n)
{
	int i;
	int digit;
	char *str;

	i = countdigit(n);
	str = (char *) malloc(sizeof(char) * i + 1);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i--] = '\0';
	while (n > 0)
	{
		digit = n % 10;
		n = n / 10;
		str[i--] = digit + '0';
	}
	return (str);
}

static int countdigit(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -(n);
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}