#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

PresidentialPardonForm::PresidentialPardonForm(): AForm()
{
	cout << "PresidentialPardonForm: Default constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(string target): AForm("presidential pardon", target, 25, 5)
{
	cout << "PresidentialPardonForm: Constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf): AForm(ppf)
{
	cout << "PresidentialPardonForm: Copy constructor called" << endl;
	*this = ppf;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &ppf)
{
	cout << "PresidentialPardonForm: Copy assignment operator called" << endl;
	(void) ppf;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "PresidentialPardonForm: Destructor called" << endl;
}

void	PresidentialPardonForm::action()
{
	cout << "PresidentialPardonForm: " << getTarget() << " has been pardoned by President Joe Biden" << endl;
}