#include "Bureaucrat.hpp"

# include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	Bureaucrat *d = new Bureaucrat();
	Bureaucrat *bob = new Bureaucrat("bob", 69);

	cout << d << endl;
	cout << bob << endl;

	delete d;
	delete bob;

	return (0);
}