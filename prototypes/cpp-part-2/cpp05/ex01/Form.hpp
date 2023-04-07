#pragma once

#ifndef FORM_HPP

#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>

using std::string;

class Form
{
	public:
		Form();
		Form(const string name, const int grade);
		Form(const Form &form);
		Form &operator = (const Form &form);
		~Form();

		string const	getName() const;
		bool const		getSignedBool() const;
		int const		getGradeToSign() const;

		void	beSigned(Bureaucrat &bureaucrat);

	private:
		string			name;
		bool			signedBool;
		int				gradeToSign;
		GradeTooHigh	GradeTooHighException;
		GradeTooLow		GradeTooLowException;

};

ostream &operator << (ostream &outs, const Form &form);

#endif