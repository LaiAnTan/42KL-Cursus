#ifndef POINT_HPP

#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);

		Point &operator = (const Point &point);

		~Point();

		Fixed const &getX();
		Fixed const &getY();
	private:
		Fixed const	x;
		Fixed const	y;
};

#endif