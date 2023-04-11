#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	try
	{
		Form	*formA = new Form("legalisation of child labor", 10);
		Form	*formB = new Form("abolish womens rights", 50);

		// error
		Form	*formC = new Form("william for president", 727);


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