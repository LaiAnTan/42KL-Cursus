#include "libft.h"

int ft_toupper(int a)
{
	if ((a >= 97) && (a <= 122))
		return(a - 32);
	else
		return(a);
}