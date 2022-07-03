#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len);

int main(void)
{
	char s1big[12] = "Foo Bar Baz";
	char s1little[4] = "Bar";
	char s2big[22] = "test test woo woo waa";
	char s2little[4] = "waa";

	char *ptr1 = ft_strnstr(s1big, s1little, 9);
	char *ptr2 = ft_strnstr(s2big, s2little, 10);

	printf("Big   : (%s)\n", s1big);
	printf("Little: (%s)\n", s1little);
	printf("My    : %p\n", ptr1);
	printf("\n");

	printf("Big   : (%s)\n", s2big);
	printf("Little: (%s)\n", s2little);
	printf("My    : %p\n", ptr2);
	printf("\n");

	return (0);

}