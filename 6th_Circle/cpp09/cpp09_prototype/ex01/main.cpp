#include "RPN.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cerr;

int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2 || rpn.insertExpression(argv[1]) == -1)
	{
		cerr << "Error" << endl; 
		return (-1);
	}
	cout << rpn.evalExpression() << endl;
	return (0);
}