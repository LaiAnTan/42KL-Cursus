#pragma once

#ifndef ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

#include <string>

using std::string;

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(string target);
		RobotomyRequestForm(const RobotomyRequestForm &rrf);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &rrf);
		~RobotomyRequestForm();

		void	action();
		static AForm	*factory(string target);
};

#endif