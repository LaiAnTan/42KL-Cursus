#include "fdf.h"

int main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (-1);
	get_map(&map, argv[1]);

	printf("%d\n", map.points[2][2].z);
	printf("%X\n", map.points[2][2].color);
}

// stuff

/*
	t_data		data;

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

	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress_event, &data);
	mlx_loop(data.mlx_ptr);

	if (data.win_ptr == NULL);
		exit(1);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
*/