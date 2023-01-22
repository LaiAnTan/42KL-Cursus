#include "Harl.hpp"

#include <iostream>
#include <string>

using	std::cout;
using	std::cerr;
using	std::endl;
using	std::string;

int	main(int argc, char **argv)
{	
	int		i = 0;
	Harl	harl;
	string	level = argv[1];
	string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
	{
		cerr << "Wrong number of arguements" << endl;
		return (-1);
	}
	while (level != levels[i++] && !levels[i - 1].empty()) {}
	switch (i)
	{
		case 1:
			cout << "[ DEBUG ]" << endl;
			harl.complain("DEBUG");
			/* fall through */
		case 2:
			cout << "[ INFO ]" << endl;
			harl.complain("INFO");
			/* fall through */
		case 3:
			cout << "[ WARNING ]" << endl;
			harl.complain("WARNING");
			/* fall through */
		case 4:
			cout << "[ ERROR ]" << endl;
			harl.complain("ERROR");
			break ;
		default:
			cout << "[ Probably complaining about insignificant problems ]" << endl;
	}
}