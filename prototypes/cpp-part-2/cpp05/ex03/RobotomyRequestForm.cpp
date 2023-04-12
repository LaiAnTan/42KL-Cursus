#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <string>

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
	if (this == &rrf)
		return (*this);
	this->name = rrf.getName();
	this->target = rrf.getTarget();
	this->signedBool = rrf.getSigned();
	this->signGrade = 72;
	this->execGrade = 45;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm: Destructor called" << endl;
}

void	RobotomyRequestForm::action()
{
	cout << "RobotomyRequestForm: " << getTarget() << " has been robotomized 50% of the time" << endl;
}

AForm	*RobotomyRequestForm::factory(string target)
{
	return (new RobotomyRequestForm(target));
}