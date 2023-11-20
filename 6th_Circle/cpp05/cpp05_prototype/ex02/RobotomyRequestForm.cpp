#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

RobotomyRequestForm::RobotomyRequestForm(): AForm()
{
	cout << "RobotomyRequestForm: Default constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(string target): AForm("robotomy request", target, 72, 45)
{
	cout << "RobotomyRequestForm: Constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf): AForm(rrf)
{
	cout << "RobotomyRequestForm: Copy constructor called" << endl;
	*this = rrf;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &rrf)
{
	cout << "RobotomyRequestForm: Copy assignment operator called" << endl;
	(void) rrf;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm: Destructor called" << endl;
}

void	RobotomyRequestForm::action()
{
	int random = std::rand() % 2;
	
	if (random == 1)
		cout << "RobotomyRequestForm: " << getTarget() << " has been succesfully robotomized" << endl;
	else
		cout << "RobotomyRequestForm: Robotomization of " << getTarget() << " has failed" << endl;
}