#include "libft.h"

int main(void)
{
	char *str = "XtestXtestXtestX";
	char **strs = ft_split(str, 'X');
	for (int i = 0; *strs[i] != '\0'; i++)
		printf("String: (%s)\n", strs[i]);
	
	return (0);
}