#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int val;
	int rt1;
	int rt2;

	val = -1;
	rt1 = ft_printf(" %u ", val);
	rt2 = printf(" %u ", val);
	printf("%d %d", rt1, rt2);
}