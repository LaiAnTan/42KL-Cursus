#include "Fixed.hpp"
#include "Point.hpp"

float	ft_abs(float num)
{
	return (num < 0 ? -num : num);
}

float	ft_sqrt(float num)
{
	float approx = num;
	float e = 0.00001;

	while (ft_abs(approx * approx - num) > e)
		approx = (approx + num / approx) / 2;
	return (approx);
}

float	ft_pow(float const num, int pow)
{
	int res = 1;

	for (pow > 0; pow--;)
		res = res * num;
	return (res);
}

float	length(Point const a, Point const b)
{
	return (ft_sqrt(ft_pow((a.getX().toFloat() + b.getX().toFloat()), 2)) + ft_pow((a.getY().toFloat() + b.getY().toFloat()), 2));
}


// semi perimeter
float	sPerimeter(Point const a, Point const b, Point const c)
{
	return ((length(a, b) + length(b, c) + length(c, a)) / 2)
}

// area using herons formula
float	area(Point const a, Point const b, Point const c)
{
	float	sP = sPerimeter(a, b, c);
	float	lenA = length(a, b);
	float	lenB = length(b, c);
	float	lenC = length(c, a);

	return (ft_sqrt(sP * (sP - lenA) * (sP - lenB) * (sP - lenC)));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
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
