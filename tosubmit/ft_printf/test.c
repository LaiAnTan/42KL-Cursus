#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int rt1;
	int rt2;

	rt1 = ft_printf(" %p ", -1);
	rt2 = printf(" %p ", -1);
	printf("%d %d", rt1, rt2);
}