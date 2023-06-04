#include "libft.h"

int main(void)
{
	
	int b1 = ft_memcmp("t\200", "t\0", 2);

	printf("My      : %d\n", b1);
	printf("\n");


	return (0);
}