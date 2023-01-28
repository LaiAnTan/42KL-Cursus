#ifndef BSP_HPP

#define BSP_HPP

#include "Point.hpp"

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point);

//math
float	ft_abs(float num);
float	ft_sqrt(float num);

//helpers
float	length(Point const &a, Point const &b);
float	area(Point const &a, Point const &b, Point const &c);

#endif