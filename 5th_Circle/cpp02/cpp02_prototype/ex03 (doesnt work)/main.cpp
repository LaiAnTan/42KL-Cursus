#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

using	std::cout;
using	std::endl;

int main( void )
{
	Point	a;
	Point	b(5, 5);
	Point	c(0, 10);
	Point	point(2.5f, 5.0f);

	cout << "Point 1: " << a << endl;
	cout << "Point 2: " << b << endl;
	cout << "Point 3: " << c << endl;
	cout << "Point x: " << point << endl;

	cout << bsp(a, b, c, point) << endl;
}
