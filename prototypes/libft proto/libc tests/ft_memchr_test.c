#include "libft.h"

void *ft_memchr(const void *s, int c, unsigned int n);

int main(void)
{
	char s1[11] = "aaaabaaaab";
	char s2[13] = "test testing";
	char s3[5] = "abcde";

	char *p1a = memchr(s1, 'b', 5); 
	char *p1b = ft_memchr(s1, 'b', 5);
	char *p2a = memchr(s2, 'i', 13);
	char *p2b = ft_memchr(s2, 'i', 13);
	char *p3a = memchr(s3, 'f', 5);
	char *p3b = ft_memchr(s3, 'f', 5);

	printf("System: %p\n", p1a);
	printf("My    : %p\n", p1b);
	printf("\n");
	printf("System: %p\n", p2a);
	printf("My    : %p\n", p2b);
	printf("\n");
	printf("System: %p\n", p3a);
	printf("My    : %p\n", p3b);

	return(0);
}