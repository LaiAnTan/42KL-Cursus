#pragma once

#ifndef INTERN_HPP

#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>

using std::exception;

class Intern
{
	public:
		Intern();
		Intern(const Intern &intern);
		Intern &operator = (const Intern &intern);
		~Intern();

		AForm* makeForm(string formName, string formTarget);

		class FormNotFoundException: public exception
		{
			public:
				const char* what() const throw();
		};
};

#endif