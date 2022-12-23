#include "fdf.h"

int encode_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

void	mlx_img_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y > HEIGHT || y < 0)
		return;
	dst = img ->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render_background(t_img *img, int color)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			mlx_img_put(img, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

// int	render_pixel(t_data *data)
// {
// 	mlx_img_put(&data ->img, data ->pixel.x, data ->pixel.y, data ->pixel.color);
// }

int	render(t_data *data)
{
	render_background(&data ->img, 0x00000000);
	if (data ->win_ptr)
		mlx_put_image_to_window(data ->mlx_ptr, data ->win_ptr, data ->img.img_ptr, 0, 0);
	return (0);
}