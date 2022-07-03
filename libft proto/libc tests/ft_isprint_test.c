#include "libft.h"

int ft_isprint(int a);

int main(void)
{
	printf("non-printables\n");
	printf(" Ascii  | System | My \n");
	printf("----------------------\n");
	for (int a = 0x00; a <= 0x1F; a++)
	{
		printf("  %04x  |    %d   |  %d \n", a, isprint(a), ft_isprint(a));
	}
	unsigned int b = 127;
	printf("  %04x  |    %d   |  %d \n", b, isprint(b), ft_isprint(b));

	printf("printables\n");
	printf(" Character |  System  |  My  \n");
	printf("-----------------------------\n");
	for (int a = 32; a <= 126 ; a++)
	{
		printf("     %c     |    %03d   |  %03d \n", a, isprint(a), ft_isprint(a));
	}
	return (0);
}