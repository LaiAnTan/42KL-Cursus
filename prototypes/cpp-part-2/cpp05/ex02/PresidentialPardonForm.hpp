#pragma once 

#ifndef PRESIDENTIAL_PARDON_FORM_HPP

#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"


#include <string>

using std::string;

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(string target);
		PresidentialPardonForm(const PresidentialPardonForm &ppf);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &ppf);
		~PresidentialPardonForm();

		void	action();
};

#endif