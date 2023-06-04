#include "libft.h"

size_t ft_strlen(const char *str);

int main(void)
{
	char *s1 = "hello";
	char *s2 = "this is a test";
	char *s3 = "";
	char *s4 = "          ";
	char *s5 = "s192w1hb23143h3h1bchjas";

	printf("String: (%s)\n", s1);
	printf("System: (%lld)\n", strlen(s1));
	printf("My    : (%lld)\n", ft_strlen(s1));
	printf("\n");

	printf("String: (%s)\n", s2);
	printf("System: (%lld)\n", strlen(s2));
	printf("My    : (%lld)\n", ft_strlen(s2));
	printf("\n");

	printf("String: (%s)\n", s3);
	printf("System: (%lld)\n", strlen(s3));
	printf("My    : (%lld)\n", ft_strlen(s3));
	printf("\n");

	printf("String: (%s)\n", s4);
	printf("System: (%lld)\n", strlen(s4));
	printf("My    : (%lld)\n", ft_strlen(s4));
	printf("\n");

	printf("String: (%s)\n", s5);
	printf("System: (%lld)\n", strlen(s5));
	printf("My    : (%lld)\n", ft_strlen(s5));
	printf("\n");

	return (0);
}