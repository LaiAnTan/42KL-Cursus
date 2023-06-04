/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:43:15 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 18:41:31 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_2d_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	assign_color(t_point **points, char **split_2, int i, int row)
{
	if (split_2[0] != NULL)
		points[i][row].z = ft_atoi(split_2[0]);
	if (split_2[1] != NULL)
		points[i][row].color = get_color(split_2[1]);
	else
		points[i][row].color = WHITE;
}

void	extract_insert_data(t_point	**points, char *line, int row, int col)
{
	int		i;
	char	**split;
	char	**split_2;

	i = 0;
	split = ft_split((char *) line, ' ');
	while (i < col)
	{
		if (is_present(split[i], ',') == 1)
		{
			split_2 = ft_split(split[i], ',');
			assign_color(points, split_2, i, row);
			free_2d_array(split_2);
		}
		else
		{
			if (split[i] != NULL)
				points[i][row].z = ft_atoi(split[i]);
			points[i][row].color = WHITE;
		}
		i++;
	}
	free_2d_array(split);
}

int	get_map(t_map *map, char *filename)
{	
	size_t	i;
	int		fd;
	char	*line;

	if (get_dimension(map, filename) == -1)
		return (-1);
	if ((int) map ->rows == -1 && (int) map ->cols == -1)
		return (-1);
	malloc_map(map);
	i = 0;
	fd = open(filename, O_RDONLY);
	while (i < map ->rows)
	{
		line = get_next_line(fd);
		line = trim_nl(line);
		if (!line)
			break ;
		extract_insert_data(map ->points, line, i, map ->cols);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
