#include "PmergeMe.hpp"

#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

bool	isValidNumber(std::string num)
{
	return (num.find_first_not_of("0123456789") == std::string::npos);
}

int main(int argc, char **argv)
{
	std::string			str;
	std::vector<int>	nums;

	PmergeMe	pm;

	if (argc == 1)
	{
		cerr << "Error: No arguments provided" << endl;
		return (-1);
	}
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		if (isValidNumber(str))
			nums.push_back(std::atoi(argv[i]));
		else
		{
			cerr << "Error: Invalid argument: " << argv[i] << endl;
			return (-1);
		}
	}
	pm.insertNumbers(nums.begin(), nums.end());
	cout << "Before: " << pm.getVec() << endl;

	pm.performFordJohnsonVec();
	cout << "After:  " << pm.getVec() << endl;

}