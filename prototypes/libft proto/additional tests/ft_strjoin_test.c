#include "libft.h"

int main(void)
{
	char *s1a = "Foo";
	char *s1b = " Bar Baz";
	char *s1c = ft_strjoin(s1a, s1b);

	printf("String 1: (%s)\n", s1a);
	printf("String 2: (%s)\n", s1b);
	printf("My      : (%s)\n", s1c);
}