#pragma once

#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP

#include "Form.hpp"

#include <string>
#include <iostream>
#include <exception>

using std::string;
using std::exception;
using std::ostream;

class Form;

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

		void			incrementGrade();
		void			decrementGrade();

		void			signForm(Form &form);

	private:
		string	name;
		int		grade;
		GradeTooHigh	GradeTooHighException;
		GradeTooLow		GradeTooLowException;

};

ostream &operator << (ostream &outs, const Bureaucrat &bureaucrat);

#endif