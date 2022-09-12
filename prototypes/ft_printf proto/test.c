#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int val;
	int rt1;
	int rt2;

	val = -1;
	rt1 = ft_printf(" %p ", &val);
	rt2 = printf(" %p ", &val);
	printf("%d %d", rt1, rt2);
}