#include "fdf.h"

int encode_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

int		*dec_to_rgb(int rgb[3], unsigned int dec)
{
	rgb[0] = (dec & 0xFF0000) >> 16;
	rgb[1] = (dec & 0x00FF00) >> 8;
	rgb[2] = (dec & 0x0000FF);
	return (rgb);
}

int		get_gradient(t_line *line, float x, float y)
{
	float	percent;
	int		rgb0[3];
	int		rgb1[3];
	int		result_rgb[3];


	percent = ((x - line ->x0) + (y - line ->y0)) / ((line ->x1 - line ->x0) +(line ->y1 - line ->y0));
	dec_to_rgb(rgb0, line ->color0);
	dec_to_rgb(rgb1, line ->color1);
	result_rgb[0] = rgb0[0] + percent * (rgb1[0] - rgb0[0]);
	result_rgb[1] = rgb0[1] + percent * (rgb1[1] - rgb0[1]);
	result_rgb[2] = rgb0[2] + percent * (rgb1[2] - rgb0[2]);

	return(encode_trgb(0, result_rgb[0], result_rgb[1], result_rgb[2]));
}

float	ft_abs(float n)
{
	if (n < 0)
	n = -n;
	return (n);
}

int		ft_max(float a, float b)
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
	increment[0] = data->line.x1 -  data ->line.x0;
	increment[1] =  data ->line.y1 - data ->line.y0;
	max = ft_max(ft_abs(increment[0]), ft_abs(increment[1]));
	increment[0] /= max;
	increment[1] /= max;

	while ((int)(coords[0] - data ->line.x1) || (int)(coords[1] - data ->line.y1))
	{
		color = get_gradient(&data->line, coords[0], coords[1]);
		mlx_img_put(&data ->img, coords[0], coords[1], color);
		coords[0] += increment[0];
		coords[1] += increment[1];
	}
}

void	vertical(t_data *data)
{
	float	x;
	float	y;
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