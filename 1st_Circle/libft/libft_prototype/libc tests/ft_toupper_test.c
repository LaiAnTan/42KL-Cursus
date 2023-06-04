#include "libft.h"

int ft_toupper(int a);

int main(void)
{
	char a = ' ';
	printf(" Character | System | My  \n");
	printf("------------------------- \n");
	for (int i = 0; i <= 94; i++)
	{
		printf("     %c     |    %c   |  %c \n", a, toupper(a), ft_toupper(a));
		a++;
	}
	return (0);
}