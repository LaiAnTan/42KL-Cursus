#include "libft.h"

void *ft_memmove(void *d, const void *s, size_t n);

int main(void)
{
	char s1a[] = "hello";
	char s1b[] = "byeee";
	char s1c[] = "byeee";
	char s2a[] = "this is a test";
	char s2b[] = "no this is not";
	char s2c[] = "no this is not";
	char s3a[] = "s192w1hb23143h3h1bchjas";
	char s3b[] = "aaaaaaaaaaaaaaaaaaaaaaa";
	char s3c[] = "aaaaaaaaaaaaaaaaaaaaaaa";

	printf("String: (%s)\n", s1a);
	memmove(s1b, s1a, 4);
	ft_memmove(s1c, s1a, 4);
	printf("System: (%s)\n", s1b);
	printf("My    : (%s)\n", s1c);
	printf("\n");

	printf("String: (%s)\n", s2a);
	memmove(s2b, s2a, 9);
	ft_memmove(s2c, s2a, 9);
	printf("System: (%s)\n", s2b);
	printf("My    : (%s)\n", s2c);
	printf("\n");

	printf("String: (%s)\n", s3a);
	memmove(s3b, s3a, 15);
	ft_memmove(s3c, s3a, 15);
	printf("System: (%s)\n", s3b);
	printf("My    : (%s)\n", s3c);
	printf("\n");

}