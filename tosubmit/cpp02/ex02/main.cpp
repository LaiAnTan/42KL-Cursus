#include "Fixed.hpp"
#include <iostream>

using	std::cout;
using	std::endl;

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	Fixed const c(Fixed(5) / Fixed( 2 ));


	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << b << endl;
	cout << Fixed::max( a, b ) << std::endl;
	cout << c << endl;

	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "b - c = " << b - c << endl;
	cout << "b + c = " << b + c << endl;
	cout << "b * c = " << b * c << endl;
	cout << "b / c = " << b / c << endl;
	cout << "max(b, c) = " << Fixed::max(b, c) << endl;
	cout << "min(b, c) = " << Fixed::min(b, c) << endl;
	return 0;
}

// Fixed (0) = int (0 + 1 / 256)
// divide by 256 (2 power of 8) because bit shift 8 times;