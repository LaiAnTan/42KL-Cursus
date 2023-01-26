#include "Point.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

Point::Point()
{
	this->x(0);
	this->y(0);
}

Point::Point(const float x, const float y)
{
	
}

Point::Point(const Point &point)
{
	*this = point;
}

Point &Point::operator = (const Point &point)
{
	if (this == &point)
		return (*this);
	this->x.setRawBits(point.x.getRawBits());
	this->y.setRawBits(point.y.getRawBits());
	return (*this);
}

Point::~Point()
{

}