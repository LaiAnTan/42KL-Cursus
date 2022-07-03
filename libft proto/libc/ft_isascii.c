#include "libft.h"

int ft_isascii(int a)
{
	if (a >= 0x00 && a <= 0x7f)
		return (1);
	else
		return (0);
}