#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int a = ft_printf("%  i\n", (int)-42);
	ft_printf("% + i\n", (int)42);
	ft_printf("%+i\n", (int)42);
	ft_printf("%    i\n", (int)42);
	/*
	int c = ft_printf("--.%#xp", 0);
	ft_printf("return: %d", c);
	*/
}