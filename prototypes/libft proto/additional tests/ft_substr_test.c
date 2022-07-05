#include "libft.h"

int main(void)
{
	char s1a[12] = "Foo Bar Baz";
	char *s1b = ft_substr(s1a, 4, 12);

	printf("String: (%s)\n", s1a);
	printf("My    : (%s)\n", s1b);
	printf("\n");

	return (0);
}