#include "libft.h"

int ft_isalnum(int a);

int main(void)
{
	char a = ' ';
	printf(" Character | System | My \n");
	printf("-------------------------\n");
	for (int i = 0; i <= 94; i++)
	{
		printf("     %c     |    %d   |  %d \n", a, isalnum(a), ft_isalnum(a));
		a++;
	}
	return (0);
}