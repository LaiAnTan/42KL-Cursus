#include <stdio.h>
#include "ft_printf.h"


int main(void)
{
	int ret = ft_printf("% d", 0);
	printf("\nreturn: %d\n", ret);
}