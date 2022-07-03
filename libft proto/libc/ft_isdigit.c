#include "libft.h"

int ft_isdigit(int a);

int ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}