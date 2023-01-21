#include <iostream>
#include <fstream>
#include <string>

using	std::cout;
using	std::endl;
using	std::getline;
using	std::fstream;
using	std::string;

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Wrong number of arguments" << endl;
		return (-1);
	}

	string		line;
	string		writeFileName(argv[1]);
	fstream		readFile(argv[1], fstream::in);
	if (!readFile.is_open())
	{
		cout << "File could not be opened";
		return (-1);
	}
	fstream		writeFile(writeFileName.append(".replace"), fstream::out);

	// getline(, line);
	// cout << line << endl;

	readFile.close();
	writeFile.close();
}