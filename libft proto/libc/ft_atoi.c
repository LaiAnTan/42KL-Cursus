#include "libft.h"

int	ft_atoi(const char *s);

int	ft_atoi(const char *s)
{
	int	n;
	int	sign;
	int	rtval;
	char *str = (char *) s;

	n = 0;
	sign = 1;
	rtval = 0;
	while (str[n] == ' ' || (str[n] >= 9 && str[n] <= 13))
		++n;
	if (str[n] == '-')
		sign *= -1;
	++n;
	while (str[n] >= '0' && str[n] <= '9')
	{
		rtval = (rtval * 10) + (str[n] - '0');
		++n;
	}
	return (rtval * sign);
}