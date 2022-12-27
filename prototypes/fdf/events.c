#include "fdf.h"

/* 
* Run this function when a key with the key_symbol is pressed 
* to get the key symbol for a key: xev in terminal and press that specific key
*/
int	keypress_event(int key_symbol, t_data *data)
{
	if (key_symbol == 0xff1b) // 'ESC'
	{
		mlx_destroy_window(data ->mlx_ptr, data ->win_ptr);
		mlx_destroy_display(data ->mlx_ptr);
		clean_exit(data);
	}
	if (key_symbol == 0xff52) // 'up arrow'
		translate(&data ->map, 0, 25);
	if (key_symbol == 0xff54) // 'down arrow'
		translate(&data ->map, 0, -25);
	if (key_symbol == 0xff51) // 'left arrow'
		translate(&data ->map, 25, 0);
	if (key_symbol == 0xff53) // 'right arrow'
		translate(&data ->map, -25, 0);
	if (key_symbol == 0x3d) // "+"
		zoom(&data ->map, 1.2);	
	if (key_symbol == 0x2d) // "-"
		zoom(&data ->map, 0.8);
	render(data);
	return (0);
}