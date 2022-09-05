#include "ft_printf.h"

int main(void)
{
	char a = 'a';
	int b = 424242;
	char *c = "testing";
	int d = 0;
	int i = ft_printf("%p", &a);
	printf("return val: %d", i);
	return (0);
}

/* 
fix ptr ret val
fix consecutive %%
value of b after a char is wrong
string crashes when ft_printf("%c %d %s", a, b, c); 
*/
