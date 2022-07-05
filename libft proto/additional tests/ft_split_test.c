#include "libft.h"

int main(void)
{
	char *s1 = "   ehe   te   nandayo paimon sucks  ass";
	char **strs = ft_split(s1, ' ');

	for(int i = 0; i < 5; i++)
		printf("string: (%s)\n", strs[i]);
   return (0);
}