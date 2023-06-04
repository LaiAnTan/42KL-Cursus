#include "Form.hpp"

#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

Form::Form()
{
	cout << "Form: Default constructor called" << endl;
	name = "default";
	signGrade = 1;
	execGrade = 1;
	signedBool = false;
}

Form::Form(const string name, const int signGrade, const int execGrade): name(name)
{
	cout << "Form: Constructor called" << endl;
	if (signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	else if  (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());
	else
	{
		this->signGrade = signGrade;
		this->execGrade = execGrade;
	}
	signedBool = false;
}

Form::Form(const Form &form)
{
	cout << "Form: Copy constructor called" << endl;
	*this = form;
}

Form &Form::operator = (const Form &form)
{
	cout << "Form: Copy assignment operator called" << endl;
	if (this == &form)
		return (*this);
	this->name = form.getName();
	this->signGrade = form.getSignGrade();
	this->execGrade = form.getExecGrade();
	this->signedBool = form.getSigned();
	return (*this);
}

Form::~Form()
{
	cout << "Form: Destructor called" << endl;
}

string const	Form::getName() const
{
	return (name);
}

bool	Form::getSigned() const
{
	return (signedBool);
}

int	Form::getSignGrade() const
{
	return (signGrade);
}

int	Form::getExecGrade() const
{
	return (execGrade);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		signedBool = true;
	else
		throw(Form::GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException: Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException: Grade is too low");
}

ostream &operator << (ostream &outs, const Form &form)
{
	outs << "Form: " << form.getName() << ", grade to sign: " << form.getSignGrade() << ", grade to exec: " << form.getExecGrade();
	if (form.getSigned() == true)
		outs << ", has been signed";
	else
		outs << ", has not been signed";
	return (outs);
}