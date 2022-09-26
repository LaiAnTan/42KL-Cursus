#include "get_next_line.h"

char    *ft_append(char *src1, char *src2)
{
    char    *append;
    char    *current;
	char	*srchead;

    append = (char *) malloc (sizeof(char) * (ft_strlen(src1) + ft_strlen(src2) + 1));
	printf("malloced");
    if (!append)
        return (0);
	srchead = src1;
    current = append;
    while (src1 != NULL && *src1)
    {
        *current = *src1;
        current++;
        src1++;
    }
	printf("src1 appended");
    while (src2 != NULL && *src2)
    {
        *current = *src2;
        current++;
        src2++;
    }
	printf("src2 appended");
    *current = '\0';
	if (srchead != NULL)
		free(srchead);
    return (append);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}