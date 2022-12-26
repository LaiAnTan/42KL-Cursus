#include "fdf.h"

void	assign_xy(t_map *map, int offset)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map ->rows)
	{
		while (x < map ->cols)
		{
			map ->points[x][y].x = x * offset;
			map ->points[x][y].y = y * offset;
			x++;
		}
		x = 0;
		y++;
	}
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map ->cols)
		free(map ->points[i++]);
	free(map ->points);
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
			printf("col: %d, row: %d, x: %d, y: %d, z: %d, color: %X\n", i, j, points[i][j].x, points[i][j].y, points[i][j].z, points[i][j].color);
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

	if (argc != 2)
		return (-1);
	if (get_map(&data.map, argv[1]))
		return (-1);
	assign_xy(&data.map, 25);
	// point_status(data.map.points, data.map.rows, data.map.cols);

	data.line.x0 = 50;
	data.line.x1 = 50;
	data.line.y0 = 0;
	data.line.y1 = HEIGHT;
	data.line.color0 = 0x00FFFF00;
	data.line.color1 = 0x000000FF;

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

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress_event, &data);
	mlx_loop(data.mlx_ptr);

	if (data.win_ptr == NULL);
		exit(1);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free_map(&data.map);
	return (0);
}
