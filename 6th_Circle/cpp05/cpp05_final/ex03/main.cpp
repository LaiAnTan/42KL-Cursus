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
	Bureaucrat	*workerA = new Bureaucrat("William", 5);

	Intern		*internA = new Intern();

	AForm		*formA = internA->makeForm("presidential pardon", "bob");
	AForm		*formB = internA->makeForm("robotomy request", "elon musk");
	AForm		*formC = internA->makeForm("shrubbery creation", "mars");

	try
	{
		AForm		*formThatDoesNotExist = internA->makeForm("sus", "amogus");
		delete formThatDoesNotExist;
	}
	catch (const Intern::FormNotFoundException& err)
	{
		std::cerr << err.what() << endl;
		
	}

	cout << *workerA << endl;

	cout << *formA << endl;
	cout << *formB << endl;
	cout << *formC << endl;

	delete workerA;
	delete internA;

	delete formA;
	delete formB;
	delete formC;

	return (0);
}