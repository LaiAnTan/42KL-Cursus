#include "libft.h"

void *ft_memset(void *s, int c, size_t n);

int main(void)
{
	char s1a[6] = "hello";
	char s1b[6] = "hello";
	char s2a[15] = "this is a test";
	char s2b[15] = "this is a test";
	char s3a[24] = "s192w1hb23143h3h1bchjas";
	char s3b[24] = "s192w1hb23143h3h1bchjas";

	printf("String: (%s)\n", s1a);
	memset(s1a, 'X', 2);
	ft_memset(s1b, 'X', 2);
	printf("System: (%s)\n", s1a);
	printf("My    : (%s)\n", s1b);
	printf("\n");

	printf("String: (%s)\n", s2a);
	memset(s2a, '#', 10);
	ft_memset(s2b, '#', 10);
	printf("System: (%s)\n", s2a);
	printf("My    : (%s)\n", s2b);
	printf("\n");

	printf("String: (%s)\n", s3a);
	memset(s3a, 'f', 23);
	ft_memset(s3b, 'f', 23);
	printf("System: (%s)\n", s3a);
	printf("My    : (%s)\n", s3b);
	printf("\n");

}