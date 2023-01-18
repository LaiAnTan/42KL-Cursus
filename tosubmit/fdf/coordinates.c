/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:33:51 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 11:56:46 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_xy(t_map *map, int distance, int x_offset, int y_offset)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map ->rows)
	{
		while (x < map ->cols)
		{
			map ->points[x][y].x = x * distance + x_offset;
			map ->points[x][y].y = y * distance + y_offset;
			map ->points[x][y].z = map ->points[x][y].z * (distance / 10);
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	translate(t_map *map, int x_offset, int y_offset)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map ->rows)
	{
		while (x < map ->cols)
		{
			map ->points[x][y].x_proj += x_offset;
			map ->points[x][y].y_proj += y_offset;
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	zoom(t_map *map, float zoom)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map ->rows)
	{
		while (x < map ->cols)
		{
			map ->points[x][y].x_proj *= zoom;
			map ->points[x][y].y_proj *= zoom;
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	iso_project(t_map *map, float cos_angle, float sin_angle)
{
	int	i;
	int	j;
	int	coords[3];

	i = 0;
	j = 0;
	while (j < map ->rows)
	{
		while (i < map ->cols)
		{
			coords[0] = map ->points[i][j].x;
			coords[1] = map ->points[i][j].y;
			coords[2] = map ->points[i][j].z;
			map ->points[i][j].x_proj = (coords[0] - coords[1])
				* cos(cos_angle);
			map ->points[i][j].y_proj = (coords[0] + coords[1])
				* sin(sin_angle) - coords[2];
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}
