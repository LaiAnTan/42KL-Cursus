#pragma once

#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

using std::string;
using std::exception;
using std::ostream;

class GradeTooHigh: public exception
{
	public:
		const char* what() const throw();
};

class GradeTooLow: public exception
{
	public:
		const char* what() const throw();
};

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat	&operator = (const Bureaucrat &bureaucrat);
		~Bureaucrat();

		string const	getName() const;
		int				getGrade() const;

		void			incrementGrade(int value);
		void			decrementGrade(int value);

	private:
		string	name;
		int		grade;
		GradeTooHigh	GradeTooHighException;
		GradeTooLow		GradeTooLowException;

};

ostream &operator << (ostream &outs, const Bureaucrat &bureaucrat);

#endif