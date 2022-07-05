#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size);

int main(void)
{

	char s1a[] = "hi";
	char s1b[10] = "hello";
	char s2a[] = "ing 1 2 3";
	char s2b[20] = "test";
	char s3a[] = "bbbbb";
	char s3b[8] = "aaaaa";
	char s4a[] = "";
	char s4b[] = "";
	
	int a;
	int b;
	int c;
	int d;

	printf("Src   : (%s)\n", s1a);
	printf("Dest  : (%s)\n", s1b);
	a = ft_strlcat(s1b, s1a, 10);
	printf("My    : (%s)\n", s1b);
	printf("Return: (%d)\n", a);
	printf("\n");

	printf("Src   : (%s)\n", s2a);
	printf("Dest  : (%s)\n", s2b);
	b = ft_strlcat(s2b, s2a, 14);
	printf("My    : (%s)\n", s2b);
	printf("Return: (%d)\n", b);
	printf("\n");

	printf("Src   : (%s)\n", s3a);
	printf("Dest  : (%s)\n", s3b);
	c = ft_strlcat(s3b, s3a, 7);
	printf("My    : (%s)\n", s3b);
	printf("Return: (%d)\n", c);
	printf("\n");

	printf("Src   : (%s)\n", s4a);
	printf("Dest  : (%s)\n", s4b);
	d = ft_strlcat(s4b, s4a, 10);
	printf("My    : (%s)\n", s4b);
	printf("Return: (%d)\n", d);
	printf("\n");
}