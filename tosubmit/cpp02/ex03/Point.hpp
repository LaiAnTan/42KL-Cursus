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

		Fixed const &getX() const;
		Fixed const &getY() const;
	private:
		Fixed const	x;
		Fixed const	y;
};

ostream &operator << (ostream &outs, const Point &point);

#endif