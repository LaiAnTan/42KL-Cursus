#include "ft_printf.h"

int main(void)
{
	char a = 'a';
	int b = 424242;
	char *c = "testing";
	int d = 0;
	int i = ft_printf("%%%%", b);
	printf("return val: %d", i);
	return (0);
}

/* 
fix ptr & hex ret val
fix consecutive %%
fix int not printing 0 char
*/
