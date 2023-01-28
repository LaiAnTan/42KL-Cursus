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
	return (ft_sqrt(ft_pow((a.getX().getRawBits() + b.getX().getRawBits()), 2) + ft_pow((a.getY().getRawBits() + b.getY().getRawBits()), 2)));
}

float	sPerimeter(Point const a, Point const b, Point const c)
{

}

float	area(Point const a, Point const b, Point const c)
{
	return ()
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{

	float area1;
	float area2;
	float area3;
}
