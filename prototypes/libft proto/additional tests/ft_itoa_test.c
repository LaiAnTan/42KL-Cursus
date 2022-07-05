#include "libft.h"

int main(void)
{
  char *a = ft_itoa(12345);
  char *b = ft_itoa(-12345);

  printf("a: (%s)\n", a);
  printf("b: (%s)\n", b);

  return (0);
}