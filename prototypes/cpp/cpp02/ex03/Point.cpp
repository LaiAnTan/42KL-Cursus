#include "Point.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

Point::Point(): x(0), y(0) {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point &point)
{
	*this = point;
}

Point &Point::operator = (const Point &point)
{
	// shits const bruh
}

Point::~Point() {}

Fixed const	&Point::getX()
{
	return (x);
}

Fixed const &Point::getY()
{
	return (y);
}