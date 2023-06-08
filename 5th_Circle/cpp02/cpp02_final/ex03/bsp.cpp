#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
#include <cmath>

using	std::cout;
using	std::endl;

bool	isEqual(Point const &a, Point const &b)
{
	return ((a.getX() == b.getX() && a.getY() == b.getY()) ? true : false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (isEqual(a, point) == true || isEqual(b, point) == true || isEqual(c, point) == true)
		return (false);
	
	Fixed	i(((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY())));
	Fixed	j(((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY())));
	Fixed	k(Fixed(1) - i - j);

	return(((i >= 0 && i <= 1) && (j >= 0 && j <= 1) && (k >= 0 && k <= 1)) ? true : false);
}

/*
barycentric coordinates - coordinates relative to points of a simplex (in this case a triangle)

so if the point is directly in between 2 vertices of a line, its coordinate would be 0.5

coordinates will fall inside the range(0, 1) if the point is located inside the triangle
*/