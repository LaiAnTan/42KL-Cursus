#include "libft.h"

int ft_isalnum(int a);

int ft_isalnum(int a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	else if (a >= 'a' && a <= 'z')
		return (2);
	else if (a >= '0' && a <= '9')
		return (4);	
	else
		return (0);
}