#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

float	ft_abs(float num)
{
	return (num < 0 ? -num : num);
}

float	ft_sqrt(float num)
{
	float approx = num;
	float e = 0.01;

	while (ft_abs(approx * approx - num) > e)
		approx = (approx + num / approx) / 2;
	return (approx);
}

float	length(Point const &a, Point const &b)
{
	float xD = (a.getX().toFloat() - b.getX().toFloat());
	float yD = (a.getY().toFloat() - b.getY().toFloat());

	float len = ft_sqrt((xD * xD) + (yD * yD));
	cout << "Length from: (" << a << ") to (" << b << "): " << len << endl;
	return (len);
}

// area using herons formula
float	area(Point const &a, Point const &b, Point const &c)
{
	float	lenA = length(a, b);
	float	lenB = length(b, c);
	float	lenC = length(c, a);
	float	sP = (lenA + lenB + lenC) / 2;
	cout << "Semi Perimeter of: (" << a << ") , (" << b << ") , (" << c << "): " << sP << endl;
	float	area = ft_sqrt(sP * (sP - lenA) * (sP - lenB) * (sP - lenC));
	cout << "Area of: (" << a << ") , (" << b << ") , (" << c << "): " << area << endl;
	return (area);
}

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	float triangleArea = area(a, b, c);
	float area1 = area(a, b, point);
	float area2 = area(b, c, point);
	float area3 = area(c, a, point);

	if (triangleArea <= (area1 + area2 + area3))
		return (false);
	else
		return (true);
}
