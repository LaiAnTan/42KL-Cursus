#include <stdio.h>

int main()
{
	int		a;

	a = 7;
	printf("%d\n", a >> 0 & 1);
	printf("%d\n", a >> 1 & 1);
	printf("%d\n", a >> 2 & 1);
	printf("%d\n", a >> 3 & 1);
}