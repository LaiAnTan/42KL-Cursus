#include "libft.h"

void *ft_memcpy(void *d, const void *s, unsigned int n);

int main(void)
{
	char s1a[6] = "aaaaa";
	char s1b[10];
	char s1c[10];

	memcpy(s1b, s1a, 6);
	ft_memcpy(s1c, s1a, 6);
	printf("String: (%s)\n", s1a);
	printf("System: (%s)\n", s1b);
	printf("My    : (%s)\n", s1c);

	return (0);
}