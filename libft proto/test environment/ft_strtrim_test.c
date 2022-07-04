#include "libft.h"

int main(void)
{
	char *s1a = "abcbbbbbbabc";
	char *s1b = "abc";
	char *s1c = ft_strtrim(s1a, s1b);

	printf("My : (%s)\n", s1c);

	return (0);
}