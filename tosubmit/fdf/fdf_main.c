/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:34:28 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 12:19:32 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map ->cols)
		free(map ->points[i++]);
	free(map ->points);
}

int	clean_exit(t_data *data)
{
	mlx_destroy_image(data ->mlx_ptr, data ->img.img_ptr);
	mlx_destroy_window(data ->mlx_ptr, data ->win_ptr);
	free(data ->mlx_ptr);
	free_map(&data ->map);
	exit(0);
	return (0);
}

int	render(t_data *data)
{
	clear_screen(data);
	draw_horizontal_lines(data);
	draw_vertical_lines(data);
	if (data ->win_ptr && data ->mlx_ptr && data ->img.img_ptr)
		mlx_put_image_to_window(data ->mlx_ptr,
			data ->win_ptr, data ->img.img_ptr, 0, 0);
	return (0);
}

/* 
* Run this function when a key with the key_symbol is pressed 
* to get the key symbol for a key: xev in terminal and press that specific key
*/
int	keypress_event(int key_symbol, t_data *data)
{
	if (key_symbol == 53)
	{
		clean_exit(data);
	}
	if (key_symbol == 126)
		translate(&data ->map, 0, 25);
	if (key_symbol == 125)
		translate(&data ->map, 0, -25);
	if (key_symbol == 123)
		translate(&data ->map, 25, 0);
	if (key_symbol == 124)
		translate(&data ->map, -25, 0);
	if (key_symbol == 24)
		zoom(&data ->map, 1.2);
	if (key_symbol == 27)
		zoom(&data ->map, 0.8);
	render(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		d;

	if (argc != 2 || get_map(&data.map, argv[1]))
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
	data.img.addr = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	render(&data);
	mlx_hook(data.win_ptr, 2, 0, &keypress_event, &data);
	mlx_hook(data.win_ptr, 17, 0, &clean_exit, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
