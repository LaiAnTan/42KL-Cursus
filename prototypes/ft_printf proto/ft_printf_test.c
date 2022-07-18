#include "libftprintf.h"

int main(void)
{
	char a = 'o';
	double n = 100;
	printf("%#g\n", n);
	ft_printf("%c\ne", a);
	return (0);
}