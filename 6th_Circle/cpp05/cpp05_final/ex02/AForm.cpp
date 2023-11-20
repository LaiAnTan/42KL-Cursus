#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

AForm::AForm(): name("default"), target("default"), signGrade(1), execGrade(1), signedBool(false)
{
	cout << "Form: Default constructor called" << endl;
}

AForm::AForm(const string name, const string target, const int signGrade, const int execGrade): name(name), target(target), signGrade(signGrade), execGrade(execGrade), signedBool(false)
{
	cout << "Form: Constructor called" << endl;
	if (signGrade < 1 || execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if  (signGrade > 150 || execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &form): name(form.getName()), target(form.getTarget()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade()), signedBool(form.getSigned())
{
	cout << "Form: Copy constructor called" << endl;
}

AForm &AForm::operator = (const AForm &form)
{
	cout << "Form: Copy assignment operator called" << endl;
	(void) form;
	return (*this);
}

AForm::~AForm()
{
	cout << "Form: Destructor called" << endl;
}

string const	AForm::getName() const
{
	return (name);
}

string const	AForm::getTarget() const
{
	return (target);
}

bool	AForm::getSigned() const
{
	return (signedBool);
}

int	AForm::getSignGrade() const
{
	return (signGrade);
}

int	AForm::getExecGrade() const
{
	return (execGrade);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		signedBool = true;
	else
		throw(AForm::GradeTooLowException());
}


void	AForm::execute(const Bureaucrat &executor)
{
	if (signedBool != true)
		throw(AForm::NotSignedException());
	else if  (executor.getGrade() > this->getExecGrade())
		throw (AForm::GradeTooLowException());
	else
		this->action();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException: Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException: Grade is too low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("NotSignedException: Form not signed");
}

ostream &operator << (ostream &outs, const AForm &form)
{
	outs << "Form: " << form.getName() << ", grade to sign: " << form.getSignGrade() << ", grade to exec: " << form.getExecGrade();
	if (form.getSigned() == true)
		outs << ", has been signed";
	else
		outs << ", has not been signed";
	return (outs);
}