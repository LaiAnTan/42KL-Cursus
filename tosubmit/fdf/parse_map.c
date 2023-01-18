/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:40:37 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 12:57:52 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*trim_nl(char *line)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	if (line == NULL)
		return (NULL);
	if (is_present(line, '\n') == 0)
		return (line);
	len = ft_strlen(line);
	ret = (char *) malloc (sizeof(char) * len);
	while (line[i] != '\n')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	free(line);
	return (ret);
}

int	get_color(char *str_color)
{
	int				base;
	int				index;
	unsigned int	hex_color;

	base = 1;
	index = ft_strlen(str_color) - 1;
	hex_color = 0;
	while (index >= 2)
	{
		if (str_color[index] >= 'A' && str_color[index] <= 'F')
			hex_color += (str_color[index] - 55) * base;
		else if (str_color[index] >= 'a' && str_color[index] <= 'f')
			hex_color += (str_color[index] - 87) * base;
		else if (str_color[index] >= '0' && str_color[index] <= '9')
			hex_color += (str_color[index] - 48) * base;
		base *= 16;
		index--;
	}
	return (hex_color);
}

int	*count_dimension(char *filename)
{
	int		fd;
	char	*line;
	int		*rc;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	rc = (int *) malloc(sizeof(int) * 2);
	rc[0] = 1;
	rc[1] = countwords((char *) line, ' ');
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (countwords((char *) line, ' ') != rc[1])
		{
			rc[0] = -1;
			rc[1] = -1;
			break ;
		}
		rc[0]++;
	}
	close(fd);
	return (rc);
}

void	get_dimension(t_map *map, char *filename)
{
	int	*rc;

	rc = count_dimension(filename);
	map ->rows = rc[0];
	map ->cols = rc[1];
	free(rc);
}

void	malloc_map(t_map *map)
{
	int		i;

	i = 0;
	map ->points = (t_point **) malloc (sizeof(t_point *) * map ->cols);
	while (i < map ->cols)
	{
		map ->points[i] = (t_point *) malloc (sizeof(t_point) * map ->rows);
		i++;
	}
}
