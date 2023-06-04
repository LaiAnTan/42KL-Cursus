#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	try
	{
		Bureaucrat	*workerA = new Bureaucrat("William", 5);
		Bureaucrat	*workerB = new Bureaucrat("Chia", 140);

		AForm		*formA = new PresidentialPardonForm("ur mom");
		AForm		*formB = new RobotomyRequestForm("Holden Hiscock");
		AForm		*formC = new ShrubberyCreationForm("home");

		cout << *workerA << endl;
		cout << *workerB << endl;

		cout << *formA << endl;
		cout << *formB << endl;
		cout << *formC << endl;

		workerA->signForm(*formA);
		workerA->signForm(*formA);
		workerB->executeForm(*formA);
		workerA->executeForm(*formA);

		workerB->signForm(*formB);
		workerA->executeForm(*formB);

		workerA->signForm(*formC);
		workerB->executeForm(*formC);
		workerA->executeForm(*formC);

		delete workerA;
		delete workerB;

		delete formA;
		delete formB;
		delete formC;
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << endl;
	}
	return (0);
}