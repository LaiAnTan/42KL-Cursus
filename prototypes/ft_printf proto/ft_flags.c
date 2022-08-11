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
	flag->signflag = 0;
	flag->spaceflag = 0;
	flag->hashflag = 0;
}