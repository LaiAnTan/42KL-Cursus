#include "Intern.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using std::string;


Intern::Intern()
{
	cout << "Intern: Default constructor called" << endl;
}

Intern::Intern(const Intern &intern)
{
	cout << "Intern: Copy constructor called" << endl;
	*this = intern;
}

Intern &Intern::operator = (const Intern &intern)
{
	cout << "Intern: Copy assignment operator called" << endl;
	(void) intern;
	return (*this);
}

Intern::~Intern()
{
	cout << "Intern: Destructor called" << endl;
}

AForm* Intern::makeForm(string formName, string formTarget)
{
	AForm	*(*func_ptr[3])(string) = {&PresidentialPardonForm::factory, &RobotomyRequestForm::factory, &ShrubberyCreationForm::factory};
	string	names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm	*form;

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formName == names[i])
			{
				form = (*func_ptr[i])(formTarget);
				cout << "Intern: Intern creates " << formName << endl;
				return (form);
			}
		}
		throw (Intern::FormNotFoundException());
	}
	catch (const FormNotFoundException& err)
	{
		cerr << "Intern: Form " << formName << " could not be created because it was not found" << endl;
		return (NULL);
	}
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("FornNotFoundException: Form not found");
}
