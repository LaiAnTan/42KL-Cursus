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
	private:
		Fixed const x;
		Fixed const y;
}


#endif