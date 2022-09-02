#include "ft_printf.h"

int main(void)
{
	char a = 'a';
	int b = 12345;
	int i = ft_printf("ee%  cee%c%cee", a, a, a);
	printf("\n");
	printf("return val: %d", i);
	return (0);
}
//1 char before format missing
// 1 char after format missing