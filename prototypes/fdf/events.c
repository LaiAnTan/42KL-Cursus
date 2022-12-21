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
		data ->win_ptr = NULL;
	}
	// if (key_symbol == 0xff52) // 'up arrow'
	// 	data ->pixel.y -= 50;
	// if (key_symbol == 0xff54) // 'down arrow'
	// 	data ->pixel.y += 50;
	// if (key_symbol == 0xff51) // 'left arrow'
	// 	data ->pixel.x -= 50;
	// if (key_symbol == 0xff53) // 'right arrow'
	// 	data ->pixel.x += 50;
	printf("Key %x pressed\n", key_symbol);
	return (0);
}

int	keyrelease_event(int key_symbol, void *data)
{
	printf("Key %x pressed\n", key_symbol);
	return (0);
}