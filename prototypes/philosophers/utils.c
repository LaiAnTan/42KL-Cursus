#include "philo.h"

static int	overflow_check(int val, char lastdigit)
{
	if (val <= 214748364)
		return (0);
	else
	{
		if (val >= 214748364 && (lastdigit > '7'))
			return (-1);
		return (0);
	}
}

int	ft_atoi(const char *s)
{
	long	rtval;
	char	*str;

	rtval = 0;
	str = (char *) s;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
	{
		return (0);
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		if (overflow_check(rtval, *str) == -1)
			return (0);
		rtval = (rtval * 10) + (*str - '0');
		str++;
	}
	return ((int)(rtval));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	char	*dest;

	i = 0;
	str = (char *) s;
	dest = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == 0)
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		dest[i] = '\0';
	return (dest);
}

long unsigned int get_curr_time(long unsigned int start_time)
{
	t_val		tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000000) + tv.tv_usec - start_time) / 1000);
}