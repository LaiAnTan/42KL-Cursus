#include <iostream>
#include <fstream>
#include <string>

using	std::cout;
using	std::endl;
using	std::getline;
using	std::string;

int main(int argc, char **argv)
{
	string		line;

	if (argc != 4)
	{
		cout << "Wrong number of arguments" << endl;
		return (-1);
	}

	// getline(, line);
	cout << line << endl;
}