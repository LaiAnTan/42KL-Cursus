#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, unsigned int n);

int main(void)
{
	char s1a[] = "aaaaa";
	char s1b[] = "abcde";
	char s2a[] = "abcde";
	char s2b[] = "ABCDE";
	char s3a[] = "test";
	char s3b[] = "test";

	int a1 = memcmp(s1a, s1b, 5);
	int b1 = ft_memcmp(s1a, s1b, 5);
	int a2 = memcmp(s2a, s2b, 5);
	int b2 = ft_memcmp(s2a, s2b, 5);
	int a3 = memcmp(s3a, s3b, 4);
	int b3 = ft_memcmp(s3a, s3b, 10);

	printf("String 1: %s\n", s1a);
	printf("String 2: %s\n", s1b);
	printf("System  : %d\n", a1);
	printf("My      : %d\n", b1);
	printf("\n");

	printf("String 1: %s\n", s2a);
	printf("String 2: %s\n", s2b);
	printf("System  : %d\n", a2);
	printf("My      : %d\n", b2);
	printf("\n");

	printf("String 1: %s\n", s3a);
	printf("String 2: %s\n", s3b);
	printf("System  : %d\n", a3);
	printf("My      : %d\n", b3);
	printf("\n");

	return (0);
}