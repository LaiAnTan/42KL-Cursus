#include "push_swap.h"

static int	overflow_check(int val, char lastdigit, int sign)
{
	if (val <= 214748364)
		return (0);
	else
	{
		if (val >= 214748364 && ((lastdigit > '7' && sign == 1) || (lastdigit > '8' && sign == -1)))
			return (-1);
		return (0);
	}
}

int	ft_atoi(const char *s, t_stack *stack)
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
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return(error(1, stack));
		if (overflow_check(rtval, *str, sign) == -1)
			return (error(2, stack));
		rtval = (rtval * 10) + (*str - '0');
		str++;
	}
	return ((int)(rtval * sign));
}