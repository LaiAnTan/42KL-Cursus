#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat()
{
	cout << "Bureaucrat: Default constructor called" << endl;
	name = "default";
	grade = 1;
}

Bureaucrat::Bureaucrat(string name, int grade): name(name)
{
	cout << "Bureaucrat: Constructor called" << endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if  (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
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
	this->name = bureaucrat.getName();
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
		throw (Bureaucrat::GradeTooHighException());
	else if  (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	cout << "Bureaucrat: Incremented " << this->getName() << "'s grade to " << this->getGrade() << endl; 
}

void	Bureaucrat::decrementGrade()
{
	this->grade++;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if  (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	cout << "Bureaucrat: Decremented " << this->getName() << "'s grade to " << this->getGrade() << endl;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		if (form.getSigned() == true)
		{
			cout << "Bureaucrat: " << form.getName() << " has already been signed" << endl;
			return ;
		}
		form.beSigned(*this);
	}
	catch (const Form::GradeTooLowException &err)
	{
		cout << "Bureaucrat: " << this->getName() << " could not sign form: " << form.getName() << " because grade was too low" << endl;
	}
	if (form.getSigned() == true)
			cout << "Bureaucrat: " << this->getName() << " signed " << form.getName() << endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException: Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException: Grade is too low");
}

ostream &operator << (ostream &outs, const Bureaucrat &bureaucrat)
{
	outs << "Bureaucrat: " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outs);
}