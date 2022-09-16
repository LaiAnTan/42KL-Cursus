#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int a = ft_printf("%  i\n", (int)-42);
	ft_printf("% + i\n", (int)42);
	ft_printf("%+i\n", (int)42);
	ft_printf("%    i\n", (int)42);
}