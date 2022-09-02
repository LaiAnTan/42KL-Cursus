#include "ft_printf.h"

int main(void)
{
	char a = 'a';
	int b = 43;
	int i = ft_printf("%#x", b);
	printf("\n");
	printf("return val: %d", i);
	return (0);
}
//1 char before format missing
// 1 char after format missing