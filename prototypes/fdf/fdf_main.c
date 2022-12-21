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

int main(void)
{
	t_data		data;

	data.line.x0 = WIDTH / 2;
	data.line.y0 = HEIGHT / 2;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (-1);
	
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "test");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (-1);
	}

	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

	/* hooks */
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress_event, &data);
	mlx_loop(data.mlx_ptr);

	if (!data.win_ptr)
		exit(0);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}