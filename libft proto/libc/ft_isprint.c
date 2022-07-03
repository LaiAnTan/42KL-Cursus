#include "libft.h"

int ft_isprint(int a)
{
	if (a >= ' ' && a <= '~')
	{
		if (a == ' ')
			return (64);
		else if ((a >= '!' && a <= '/') || (a >= ':' && a <= '@') || (a >= '[' && a <= '`') || (a >= '{' && a <= '~'))
			return (16);
		else if (a >= '0' && a <= '9')
			return (4);
		else if (a >= 'a' && a <= 'z')
			return (2);
		else if (a >= 'A' && a <= 'Z')
			return (1);
	}
	return (0);
}