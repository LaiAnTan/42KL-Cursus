#include "PmergeMe.hpp"

#include <sys/time.h>
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
	struct timeval	start;
	struct timeval	end;

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

	gettimeofday(&start, NULL);
	pm.performFordJohnsonVec();
	gettimeofday(&end, NULL);
	pm.setElapsedVec((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec));

	// gettimeofday(&start, NULL);
	// pm.performFordJohnsonLst();
	// gettimeofday(&end, NULL);
	// pm.setElapsedLst((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec));

	cout << "Before: " << nums << endl;
	cout << "After:  " << pm.getVec() << endl;
	cout << "Time to process a range of " << nums.size() << " elements with std::vector: " << pm.getElapsedVec() << " µs" << endl;
	cout << "Time to process a range of " << nums.size() << " elements with std::list: " << pm.getElapsedLst() << " µs" << endl;

}