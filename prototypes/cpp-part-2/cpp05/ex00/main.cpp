#include "Bureaucrat.hpp"

# include <iostream>
# include <exception>

using std::cout;
using std::endl;
using std::exception;

int main(void)
{
	try
	{
		Bureaucrat *d = new Bureaucrat();
		Bureaucrat *bob = new Bureaucrat("bob", 69);

		cout << *d << endl;
		cout << *bob << endl;

		d = bob;

		cout << *d << endl;
		cout << *bob << endl;

		bob->incrementGrade(20);
		cout << *bob << endl;
		bob->decrementGrade(1);
		cout << *bob << endl;

		//GradeTooHighException
		// bob->incrementGrade(200);

		// GradeTooLowException
		d->decrementGrade(200);

		delete d;
		delete bob;
	}
	catch (const exception &err)
	{
		cout << err.what() << endl;
	}
	return (0);
}