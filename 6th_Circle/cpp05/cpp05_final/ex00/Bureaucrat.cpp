#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat(): name("default")
{
	cout << "Bureaucrat: Default constructor called" << endl;
	grade = 1;
}

Bureaucrat::Bureaucrat(string name, int grade): name(name)
{
	cout << "Bureaucrat: Constructor called" << endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException);
	else if  (grade > 150)
		throw (Bureaucrat::GradeTooLowException);
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	cout << "Bureaucrat: Copy constructor called" << endl;
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bureaucrat)
{
	cout << "Bureaucrat: Copy assignment operator called" << endl;
	if (this == &bureaucrat)
		return (*this);
	this->grade = bureaucrat.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat: Destructor called" << endl;
}

string const Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	this->grade--;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException);
	else if  (grade > 150)
		throw (Bureaucrat::GradeTooLowException);
	cout << "Bureaucrat: Incremented " << this->getName() << "'s grade to " << this->getGrade() << endl; 
}

void	Bureaucrat::decrementGrade()
{
	this->grade++;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException);
	else if  (grade > 150)
		throw (Bureaucrat::GradeTooLowException);
	cout << "Bureaucrat: Decremented " << this->getName() << "'s grade to " << this->getGrade() << endl;
}

ostream &operator << (ostream &outs, const Bureaucrat &bureaucrat)
{
	outs << "Bureaucrat: " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outs);
}

const char* GradeTooHigh::what() const throw()
{
	return ("GradeTooHighException: Grade is too high");
}

const char* GradeTooLow::what() const throw()
{
	return ("GradeTooLowException: Grade is too low");
}