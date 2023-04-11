#include "Form.hpp"

#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;
using std::string;

Form::Form()
{
	cout << "Form: Default constructor called" << endl;
	name = "default";
	grade = 1;
	signedBool = false;
}

Form::Form(const string name, const int grade): name(name)
{
	cout << "Form: Constructor called" << endl;
	if (grade < 1)
		throw (Form::GradeTooHighException);
	else if  (grade > 150)
		throw (Form::GradeTooLowException);
	else
		this->grade = grade;
	signedBool = false;
}

Form::Form(const Form &form)
{
	*this = form;
}

Form &Form::operator = (const Form &form)
{
	if (this == &form)
		return (*this);
	this->name = form.getName();
	this->grade = form.getGrade();
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

int	Form::getGrade() const
{
	return (grade);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGrade())
		signedBool = true;
	else
		throw(Form::GradeTooLowException);
}
