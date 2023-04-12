#pragma once

#ifndef SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

#include <string>

using std::string;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &scf);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &scf);
		~ShrubberyCreationForm();

		void	action();
};

#endif