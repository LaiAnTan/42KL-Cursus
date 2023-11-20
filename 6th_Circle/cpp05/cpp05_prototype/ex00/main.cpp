#include "Bureaucrat.hpp"

# include <iostream>
# include <exception>

using std::cout;
using std::endl;
using std::exception;

int main(void)
{
	Bureaucrat *william = new Bureaucrat("child predator", 150);
	Bureaucrat *bob = new Bureaucrat("bob", 69);
	Bureaucrat *dave = new Bureaucrat("dave", 1);

	cout << *william << endl;
	cout << *bob << endl;
	cout << *dave << endl;

	bob->incrementGrade();
	cout << *bob << endl;
	bob->decrementGrade();
	cout << *bob << endl;

	// GradeTooLowException
	try
	{
		william->decrementGrade();
	}
	catch (const GradeTooLow &e)
	{
		std::cerr << e.what() << endl;
	}

	// GradeTooHighException
	try
	{
		dave->incrementGrade();
	}
	catch (const GradeTooHigh &e)
	{
		std::cerr << e.what() << endl;
	}

	delete william;
	delete bob;
	delete dave;

	return (0);
}