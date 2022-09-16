#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *test = "babdasbd";
	int a = ft_printf("The address is %p, so what?\n", &test);
	printf("return: %d\n", a);
	int b = printf("The address is %p, so what?\n", &test);
	printf("return: %d\n", b);
}