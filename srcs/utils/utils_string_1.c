#include "../../headers/minishell.h"

int	is_numeric(char *str)
{

	while (*str != '\0')
	{
		if ((*str < '0' || *str > '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	// maybe i should include a failswitch as well~
	if (!s1 || !s2)
		return (!(!s1 && !s2));
	while ((s1[i] == s2[i]))
	{
		if (s1[i] == '\0')
			return (0);
		++i;
	}
	return (s1[i] - s2[i]);
}

// s1 IS THE FULL STRING, s2 IS TO MATCH
// s1 IS PATH=ABCDEF, s2 is $PATH
int	ft_strcmp_equals(char *s1, char *s2)
{
	int		i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
	{
		++i;
	}
	if (s1[i] == '=' && s2[i] == '\0')
		return 0;
	return (s1[i] - s2[i]);
}

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