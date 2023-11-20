#pragma once

#ifndef AFORM_HPP

#define AFORM_HPP

#include "Bureaucrat.hpp"

#include <exception>
#include <string>

using std::string;
using std::ostream;
using std::exception;

class Bureaucrat;

class AForm
{
	public:
		AForm &operator = (const AForm &form);
		virtual ~AForm();

		string const	getName() const;
		string const	getTarget() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		void			beSigned(Bureaucrat &bureaucrat);
		void			execute(const Bureaucrat &executor);
		virtual void	action() = 0;

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

		class NotSignedException: public exception
		{
			public:
				const char* what() const throw();
		};

	protected:
		AForm();
		AForm(const string name, const string target, const int signGrade, const int execGrade);
		AForm(const AForm &form);

		const string	name;
		string			target;
		const int		signGrade;
		const int		execGrade;
		bool			signedBool;
};

ostream &operator << (ostream &outs, const AForm &form);

#endif