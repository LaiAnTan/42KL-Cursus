#include "libft.h"

int ft_isalpha(int a);

int main(void)
{
	char a = ' ';
	printf(" Character | System | My \n");
	printf("-------------------------\n");
	for (int i = 0; i <= 94; i++)
	{
		printf("     %c     |    %d   |  %d \n", a, isalpha(a), ft_isalpha(a));
		a++;
	}
	return (0);
}