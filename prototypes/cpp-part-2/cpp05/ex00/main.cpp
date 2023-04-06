#include "Bureaucrat.hpp"

# include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	try
	{
		Bureaucrat *d = new Bureaucrat();
		Bureaucrat *bob = new Bureaucrat("bob", 69);
		Bureaucrat *error = new Bureaucrat("bob", 200);

		cout << *d << endl;
		cout << *bob << endl;
		cout << *error << endl;

		delete d;
		delete bob;
	}
	catch (const GradeTooHigh &err)
	{
		cout << "Exception caught" << endl;
	}
	catch (const GradeTooLow *err)
	{
		cout << "Exception caught" << endl;
	}
	return (0);
}