#include "libft.h"

void test(unsigned int x, char *y)
{
	y[x] += 2;
}

int main(void)
{
	char s1[11] = "aaaaaaaaaa";
	printf("String :(%s)\n", s1);
	ft_striteri(s1, test);
	printf("My     :(%s)\n", s1);

	return (0);
}