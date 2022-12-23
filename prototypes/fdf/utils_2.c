#include "fdf.h"

int	ft_atoi(const char *s)
{
	int		sign;
	long	rtval;
	char	*str;

	sign = 1;
	rtval = 0;
	str = (char *) s;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (rtval >= 214748364 && *str > '7' && sign == 1)
			return (-1);
		if (rtval >= 214748364 && *str > '8' && sign == -1)
			return (0);
		rtval = (rtval * 10) + (*str - '0');
		str++;
	}
	return ((int)(rtval * sign));
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
