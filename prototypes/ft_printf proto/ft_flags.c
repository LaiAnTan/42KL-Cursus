#include "ft_printf.h"

t_flags	*ft_genflag(void)
{
	t_flags	*flag;
	
	flag = (t_flags *) malloc(sizeof(t_flags));
	ft_resetflag(flag);
	return (flag);
}

void	ft_resetflag(t_flags *flag)
{
	flag -> type = 0;
	flag -> signflag = 0;
	flag -> spaceflag = 0;
	flag -> hashflag = 0;
}


int	ft_countformat(char *str, int i) //i = pos of %
{
	int	n;
	int	percentcount;

	n = i;
	percentcount = 0;
	if (str[n] == '%' && str[n + 1] == '%')
		return (1);
	while ((str[n] == '%') || (str[n] == '#') || (str[n] == '+') || (str[n] == ' '))
		n++;
	return (n - i);
}