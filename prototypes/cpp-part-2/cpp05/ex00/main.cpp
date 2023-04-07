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

		//GradeTooLowException
		// william->decrementGrade();

		// GradeTooHighException
		// bob->incrementGrade();

		delete william;
		delete bob;
		delete dave;
	}
	catch (const exception &err)
	{
		std::cerr << err.what() << endl;
	}
	return (0);
}