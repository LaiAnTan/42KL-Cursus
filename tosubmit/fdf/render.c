#include "fdf.h"

void	mlx_img_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y > HEIGHT || y < 0)
		return;
	dst = img ->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	clear_screen(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			mlx_img_put(&data ->img, i, j, 0x00000000);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	place_points(t_data *data)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (j < data ->map.rows)
	{
		while (i < data ->map.cols)
		{
			mlx_img_put(&data ->img, data ->map.points[i][j].x, data ->map.points[i][j].y, data ->map.points[i][j].color);
			i++;
		}
		i = 0;
		j++;
	}
}
/*
function that draws two lines from a point to its adjacent points
lines drawn are right and downwards
process is repeated for all points except the edges
*/
void	draw_horizontal_lines(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < data ->map.rows)
	{
		while (i + 1 < data ->map.cols)
		{
			data ->line.x0 = data->map.points[i][j].x_proj;
			data ->line.y0 = data->map.points[i][j].y_proj;
			data ->line.x1 = data->map.points[i + 1][j].x_proj;
			data ->line.y1 = data->map.points[i + 1][j].y_proj;
			data ->line.color0 = data ->map.points[i][j].color;
			data ->line.color1 = data ->map.points[i + 1][j].color;
			bressenham(data);
			i++;
		}
		i = 0;
		j++;
	}
}

void	draw_vertical_lines(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data ->map.cols)
	{
		while (j + 1 < data ->map.rows)
		{
			data ->line.x0 = data->map.points[i][j].x_proj;
			data ->line.y0 = data->map.points[i][j].y_proj;
			data ->line.x1 = data->map.points[i][j + 1].x_proj;
			data ->line.y1 = data->map.points[i][j + 1].y_proj;
			data ->line.color0 = data ->map.points[i][j].color;
			data ->line.color1 = data ->map.points[i][j + 1].color;
			if (data ->line.x0 != data ->line.x1)
				bressenham(data);
			else
				vertical(data);
			j++;
		}
		j = 0;
		i++;
	}
}


int	render(t_data *data)
{
	clear_screen(data);
	draw_horizontal_lines(data);
	draw_vertical_lines(data);
	if (data ->win_ptr && data ->mlx_ptr && data ->img.img_ptr)
		mlx_put_image_to_window(data ->mlx_ptr, data ->win_ptr, data ->img.img_ptr, 0, 0);
	return (0);
}