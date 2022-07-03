#include "libft.h"

int ft_isascii(int a);

int main(void)
{
	char b = 0x00;
	printf("non-printables\n");
	printf(" Ascii | System | My \n");
	printf("---------------------\n");
	for (int a = 0x00; a<= 0x1f; a++)
	{
		printf(" %04x  |    %d   |  %d \n", a, isascii(a), ft_isascii(a));
		b++;
	}
	b = 0x7f;
	printf(" %04x  |    %d   |  %d \n", b, isascii(b), ft_isascii(b));
	b = 0x20;
	printf("printables\n");
	printf(" Ascii | Character | System | My \n");
	printf("---------------------------------\n");
	for (int a = 0x20; a <= 0x7e; a++)
	{
		printf(" %04x  |     %c     |    %d   |  %d \n", a, b, isascii(a), ft_isascii(a));
		b++;
	}
	return (0);
}