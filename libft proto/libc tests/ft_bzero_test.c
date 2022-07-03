#include "libft.h"

void ft_bzero(void *s, size_t n);

int main(void)
{
	char s1a[] = "abcdef";
	char s1b[] = "abcdef";
	char s2a[] = "aaaaaaaaaa";
	char s2b[] = "aaaaaaaaaa";
	char s3a[] = "";
	char s3b[] = "";

	printf("String : (%s)\n", s1a);
	ft_bzero(s1b, 6);
	printf("My     : (%s)\n", s1b);
	printf("\n");

	printf("String : (%s)\n", s2a);
	ft_bzero(s2b, 1);
	printf("My     : (%s)\n", s2b);
	printf("\n");

	printf("String : (%s)\n", s3a);
	ft_bzero(s3b, 6);
	printf("My     : (%s)\n", s3b);
	printf("\n");

	return (0);
}