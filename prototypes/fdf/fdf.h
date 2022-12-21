#ifndef FDF_H

# define FDF_H

# define WIDTH 1080

# define HEIGHT 720

# define PI 3.1415

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/X.h>

typedef struct s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		color;
}			t_line;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_line		line;
}				t_data;

/* 
locates the pixel's first byte address, and then 
buffers the pixel to a image, then 
puts that pixel on the screen
*/
void	mlx_img_put(t_img *img, int x, int y, int color);

// events
int		keypress_event(int key_symbol, t_data *data);
int		keyrelease_event(int key_symbol, void *data);

// render
int		render(t_data *data);

#endif