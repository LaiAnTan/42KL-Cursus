#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		check_strchr(char *s, int c, int offset)
{
	char		*str;

	if (!(str = ft_strchr(s, c)))
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
	char *s2 = "";

	check_strchr(s1, '\0', 7);
	check_strchr(s2, '\0', 0);
	return(0);
}