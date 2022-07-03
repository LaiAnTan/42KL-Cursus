#include "libft.h"

int	ft_atoi(const char *s);

int main(void)
{
	char s1[19] = "    -12345";

	int a = ft_atoi(s1);
	printf("String: (%s)\n", s1);
	printf("Val   : (%d)\n", a);

	return  (0);
}