/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:54:34 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 11:56:37 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float n)
{
	if (n < 0)
	n = -n;
	return (n);
}

int	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	bressenham(t_data *data)
{
	int				max;
	unsigned int	color;
	float			coords[2];
	float			increment[2];

	coords[0] = data ->line.x0;
	coords[1] = data ->line.y0;
	increment[0] = data->line.x1 - data ->line.x0;
	increment[1] = data ->line.y1 - data ->line.y0;
	max = ft_max(ft_abs(increment[0]), ft_abs(increment[1]));
	increment[0] /= max;
	increment[1] /= max;
	while ((int)(coords[0] - data ->line.x1)
		|| (int)(coords[1] - data ->line.y1))
	{
		color = get_gradient(&data->line, coords[0], coords[1]);
		mlx_img_put(&data ->img, coords[0], coords[1], color);
		coords[0] += increment[0];
		coords[1] += increment[1];
	}
}

void	vertical(t_data *data)
{
	float			x;
	float			y;
	unsigned int	color;

	x = data ->line.x0;
	y = data ->line.y0;
	while (y <= data ->line.y1)
	{
		color = get_gradient(&data ->line, x, y);
		mlx_img_put(&data->img, x, y, color);
		y++;
	}
}
