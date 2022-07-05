#include "libft.h"

char *ft_strchr(const char *s, int c);

int main(void)
{
	char s1[11] = "aaaabaaaab";
	char s2[13] = "test testing";
	char s3[5] = "abcde";

	char *p1a = strchr(s1, 'b'); 
	char *p1b = ft_strchr(s1, 'b');
	char *p2a = strchr(s2, 'i');
	char *p2b = ft_strchr(s2, 'i');
	char *p3a = strchr(s3, 'f');
	char *p3b = ft_strchr(s3, 'f');

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