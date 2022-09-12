#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char a = 'a';
	int b = 12345;
	int b2 = -12345;
	char *c = "string";

	int i = ft_printf("", b);
	printf("return val: %d", i);
	return (0);
}