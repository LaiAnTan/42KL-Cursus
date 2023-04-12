#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	try
	{
		Bureaucrat	*workerA = new Bureaucrat("William", 5);

		Intern		*internA = new Intern();

		AForm		*formA = internA->makeForm("presidential pardon", "bob");
		AForm		*formB = internA->makeForm("robotomy request", "elon musk");
		AForm		*formC = internA->makeForm("shrubbery creation", "mars");
		AForm		*formThatDoesNotExist = internA->makeForm("sus", "amogus");

		cout << *workerA << endl;

		cout << *formA << endl;
		cout << *formB << endl;
		cout << *formC << endl;

		delete workerA;
		delete internA;

		delete formA;
		delete formB;
		delete formC;
		delete formThatDoesNotExist;
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << endl;
	}
	return (0);
}