/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:32:45 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 11:54:51 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	encode_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

int	*dec_to_rgb(int rgb[3], unsigned int dec)
{
	rgb[0] = (dec & 0xFF0000) >> 16;
	rgb[1] = (dec & 0x00FF00) >> 8;
	rgb[2] = (dec & 0x0000FF);
	return (rgb);
}

int	get_gradient(t_line *line, float x, float y)
{
	float	percent;
	int		rgb0[3];
	int		rgb1[3];
	int		result_rgb[3];

	percent = ((x - line ->x0) + (y - line ->y0))
		/ ((line ->x1 - line ->x0) +(line ->y1 - line ->y0));
	dec_to_rgb(rgb0, line ->color0);
	dec_to_rgb(rgb1, line ->color1);
	result_rgb[0] = rgb0[0] + percent * (rgb1[0] - rgb0[0]);
	result_rgb[1] = rgb0[1] + percent * (rgb1[1] - rgb0[1]);
	result_rgb[2] = rgb0[2] + percent * (rgb1[2] - rgb0[2]);
	return (encode_trgb(0, result_rgb[0], result_rgb[1], result_rgb[2]));
}
