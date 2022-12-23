/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:19:52 by tlai-an           #+#    #+#             */
/*   Updated: 2022/12/23 17:12:50 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*output;
	char			**temp;
	static char		*content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	content = transfer(fd, content, buffer);
	if (!content)
		return (NULL);
	temp = seperate_nl(content);
	output = ft_strdup(temp[0]);
	free(temp[0]);
	if (content)
		free(content);
	content = ft_strdup(temp[1]);
	free(temp[1]);
	if (*content == '\0')
	{
		free(content);
		content = NULL;
	}
	free(temp);
	return (output);
}

int	check_nl(char *str, int size)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (i < size && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	**seperate_nl(char *str)
{
	int		i;
	int		j;
	int		len;
	char	**arr;

	len = ft_strlen(str);
	i = check_nl(str, len);
	if (i == -1)
		i = len;
	j = 0;
	arr = (char **) malloc (sizeof(char *) * 2);
	arr[0] = (char *) malloc (sizeof(char) * (i + 2));
	arr[1] = (char *) malloc (sizeof(char) * (len - i + 1));
	while (j <= i && str[j])
	{
		arr[0][j] = str[j];
		j++;
	}
	arr[0][j] = '\0';
	i = 0;
	while (str[j] != '\0')
		arr[1][i++] = str[j++];
	arr[1][i] = '\0';
	return (arr);
}

char	*transfer(int fd, char *content, char *buffer)
{
	int		bytesread;

	bytesread = 0;
	while (check_nl(buffer, bytesread) == -1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (!bytesread)
			break ;
		if (bytesread == -1)
			break ;
		buffer[bytesread] = '\0';
		content = ft_append(content, buffer);
	}
	free(buffer);
	return (content);
}

char	*ft_append(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1 != NULL)
	{
		while (s1[j] != '\0')
			temp[i++] = s1[j++];
	}
	if (s2 != NULL)
	{
		while (*s2 != '\0')
			temp[i++] = *s2++;
	}
	temp[i] = '\0';
	free(s1);
	return (temp);
}