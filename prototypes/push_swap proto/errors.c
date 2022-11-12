#include "push_swap.h"

int	error(int code, int *arr) // arr = stack to be freed
{
	if (code == 1)
		printf("Error, Arguement not an integer\n");
	else if (code == 2)
		printf("Error, Arguement overflow\n");
	else if (code == 3)
		printf("Error, Duplicate arguements found\n");
	free(arr);
	exit(code);
	return (0);
}

int	check_duplicate(int	*arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (i == j++)
				continue ;
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;

	}
	return (0);
}