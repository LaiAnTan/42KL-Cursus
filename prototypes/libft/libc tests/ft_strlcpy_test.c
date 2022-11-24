#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size);

int main(void)
{

	char s1a[6] = "hello";
	char s1b[6];
	char s2a[15] = "this is a test";
	char s2b[15];
	char s3a[24] = "s192w1hb23143h3h1bchjas";
	char s3b[24];

	ft_strlcpy(s1b, s1a, 5);
	ft_strlcpy(s2b, s2a, 16);
	ft_strlcpy(s3b, s3a, 17);

	printf("String: (%s)\n", s1a);
	printf("My    : (%s)\n", s1b);
	printf("\n");

	printf("String: (%s)\n", s2a);
	printf("My    : (%s)\n", s2b);
	printf("\n");

	printf("String: (%s)\n", s3a);
	printf("My    : (%s)\n", s3b);
	printf("\n");
}