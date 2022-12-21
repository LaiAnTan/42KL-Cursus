#include "fdf.h"

ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}


void	plot_line_low(int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		yi;
	int		diff;

	dx = x1 - x0;
	dy = y1 - y0;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	diff = (2 * dx) - dy;
	while (x0 <= x1)
	{
		put_pixel(x0, y0);
		if (diff > 0)
		{
			y0 += yi;
			diff = diff + (2 * (dx - dy));
		}
		else
			diff = diff + 2 * dx;
		x0++;
	}
}

void	plot_line(int x0, int y0, int x1, int y1)
{
	if (ft_abs(y1 - y0) < ft_abs(x1 - x0))
	{
		if (x0 > x1)
			plot_line_low(x1, y1, x0, y0);
		else
			plot_line_low(x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			plot_line_high(x1, y1, x0, y0);
		else
			plot_line_high(x0, y0, x1, y1);
	}
}