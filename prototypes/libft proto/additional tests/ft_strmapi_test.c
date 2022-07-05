#include "libft.h"

char test(unsigned int x, char y)
{
	char	a;
	(void) x;

	a = y + 2;
	return (a);
}

int main(void)
{
	char *s1 = "aaaaaaaaaa";
	char *s2 = ft_strmapi(s1, test);
	printf("String :(%s)\n", s1);
	printf("My     :(%s)\n", s2);

	return (0);
}