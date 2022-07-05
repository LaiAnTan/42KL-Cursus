#include "libft.h"

int ft_tolower(int a)
{
	if ((a >= 65) && (a <= 90))
		return(a + 32);
	else
		return(a);
}