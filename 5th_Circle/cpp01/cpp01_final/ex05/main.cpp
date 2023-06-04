#include "Harl.hpp"
#include <iostream>

using std::cout;
using std::endl;


int	main(void)
{
	Harl	harl;

	cout << "[DEBUG]" << endl;
	harl.complain("DEBUG");

	cout << "[INFO]" << endl;
	harl.complain("INFO");

	cout << "[WARNING]" << endl;
	harl.complain("WARNING");

	cout << "[ERROR]" << endl;
	harl.complain("ERROR");
}