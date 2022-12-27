#include "fdf.h"

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map ->cols)
		free(map ->points[i++]);
	free(map ->points);
}

void	clean_exit(t_data *data)
{
	mlx_destroy_image(data ->mlx_ptr, data ->img.img_ptr);
	mlx_destroy_window(data ->mlx_ptr, data ->win_ptr);
	mlx_destroy_display(data ->mlx_ptr);
	free(data ->mlx_ptr);
	free_map(&data ->map);
	exit(0);
}

void	point_status(t_point **points, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("rows: %d, cols: %d\n", rows, cols);
	while (j < rows)
	{
		while (i < cols)
		{
			printf("col: %d, row: %d, x: %d, y: %d, z: %d, xp: %f, yp: %f, color: %X\n", i, j, points[i][j].x, points[i][j].y, points[i][j].z, points[i][j].x_proj, points[i][j].y_proj, points[i][j].color);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

int main(int argc, char **argv)
{
	t_data	data;
	int	d;

	if (argc != 2)
		return (-1);
	if (get_map(&data.map, argv[1]))
		return (-1);
	d = (WIDTH + HEIGHT) / (1.5 * (data.map.cols + data.map.rows));
	assign_xy(&data.map, d, 0, 0);
	iso_project(&data.map, 0.5, 0.7);

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (-1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, argv[1]);
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (-1);
	}

	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

	render(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress_event, &data);
	mlx_loop(data.mlx_ptr);

	return (0);
}
