#include "ft_printf.h"

int main(void)
{
	char c = 'b';
	int i = ft_printf("% c\n", c);
	ft_printf("%d\n", i);
	return (0);
}