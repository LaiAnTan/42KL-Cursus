#include "libft.h"

char *ft_strdup(const char *s);

int main(void)
{
	char *s1 = "hehehehe";
	char *s2 = strdup(s1);
	char *s3 = ft_strdup(s1);

	printf("String 1: (%s)\n", s1);
	printf("System  : (%s)\n", s2);
	printf("My      : (%s)\n", s3);

	return (0);
}