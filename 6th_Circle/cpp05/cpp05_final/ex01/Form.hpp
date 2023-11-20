#pragma once

#ifndef FORM_HPP

#define FORM_HPP

#include "Bureaucrat.hpp"

#include <exception>
#include <string>

using std::string;
using std::ostream;
using std::exception;

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const string name, const int signGrade, const int execGrade);
		Form(const Form &form);
		Form &operator = (const Form &form);
		~Form();

		string const	getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void	beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException: public exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const string	name;
		const int		signGrade;
		const int		execGrade;
		bool			signedBool;

};

ostream &operator << (ostream &outs, const Form &form);

#endif