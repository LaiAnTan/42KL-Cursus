#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		check_strrchr(char *s, int c, int offset)
{
	char		*str;
	
	if (!(str = ft_strrchr(s, c)))
		ft_print_result("NULL");
	else
	{
		ft_print_result(str);
		if (str != (s + offset))
			ft_print_result("\nReturn value is false");
	}
}

int main(void)
{
	char *s1 = "bonjour";

	check_strrchr(s1, 'b', 0);

	return(0);
}