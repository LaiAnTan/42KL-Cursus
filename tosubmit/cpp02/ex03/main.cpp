#include <iostream>

#include "Point.hpp"
#include "bsp.hpp"

using	std::cout;
using	std::endl;

int main( void )
{
	Point	a;
	Point	b(5, 5);
	Point	c(0, 10);
	Point	x(2, 3);

	cout << "Point 1: " << a << endl;
	cout << "Point 2: " << b << endl;
	cout << "Point 3: " << c << endl;
	cout << "Point x: " << x << endl;

	cout << bsp(a, b, c, x) << endl;
}
