#pragma once

#ifndef FORM_HPP

#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <exception>

using std::string;
using std::ostream;

class Bureaucrat;

class GradeTooHigh;
class GradeTooLow;

class Form
{
	public:
		Form();
		Form(const string name, const int grade);
		Form(const Form &form);
		Form &operator = (const Form &form);
		~Form();

		string const	getName() const;
		bool getSigned() const;
		int getGrade() const;

		void	beSigned(Bureaucrat &bureaucrat);

	private:
		string			name;
		bool			signedBool;
		int				grade;
		GradeTooHigh	GradeTooHighException;
		GradeTooLow		GradeTooLowException;
};

ostream &operator << (ostream &outs, const Form &form);

#endif