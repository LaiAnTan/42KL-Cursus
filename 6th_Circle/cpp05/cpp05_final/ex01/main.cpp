#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	try
	{
		Bureaucrat	*workerA = new Bureaucrat("William", 5);
		Bureaucrat	*workerB = new Bureaucrat("Chia", 99);

		cout << *workerA << endl;
		cout << *workerB << endl;

		Form	*formA = new Form("legalisation of child labor", 10, 25);
		Form	*formB = new Form("abolish womens rights", 50, 100);

		try
		{
			Form	*formC = new Form("william for president", 727, 727);
			delete formC;
		}
		catch (const Form::GradeTooLowException& err)
		{
			cout << err.what() << endl;
		}

		workerB->signForm(*formA);
		workerA->signForm(*formA);
		workerB->signForm(*formB);

		cout << *formA << endl;
		cout << *formB << endl;

		delete workerA;
		delete workerB;

		delete formA;
		delete formB;
		// delete formC;
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << endl;
	}

	return (0);
}