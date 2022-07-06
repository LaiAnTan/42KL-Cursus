#include "libft.h"

static void		ft_print_result(char *s)
{
	int		len;

	if (!s)
		write(1, "NULL", 4);
	else
	{
		len = 0;
		while (s[len])
			len++;
		write(1, s, len);
		free(s);
	}
	printf("\n");
}

int main(void)
{
  ft_print_result(ft_itoa(0));
  ft_print_result(ft_itoa(-9));
  ft_print_result(ft_itoa(-10));
  ft_print_result(ft_itoa(-9874));
  ft_print_result(ft_itoa(-2147483648));

  return (0);
}