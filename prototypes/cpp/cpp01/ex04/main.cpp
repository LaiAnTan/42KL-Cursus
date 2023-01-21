#include <iostream>
#include <fstream>
#include <string>

using	std::cout;
using	std::endl;
using	std::getline;
using	std::fstream;
using	std::string;

string	reconstructString(string line, string toFind, string toReplace)
{
	int		i = 0;
	size_t	occurPos = 0;
	size_t	remainder = 0;
	string	newString;

	occurPos = line.find(toFind, occurPos);
	while (occurPos != string::npos)
	{
		newString.append(line.substr(i, occurPos - i));
		i = occurPos + toFind.length();
		occurPos = line.find(toFind, occurPos + 1);
		newString.append(toReplace);
		
	}
	remainder = line.rfind(toFind);
	if (remainder != string::npos)
		remainder += toFind.length();
	else
		remainder = 0;
	newString.append(line.substr(remainder, line.length()));
	return (newString);
}

int main(int argc, char **argv)
{
	string		readLine;
	string		replaceLine;
	fstream		readFile;
	fstream		writeFile;

	if (argc != 4)
	{
		cout << "Wrong number of arguments" << endl;
		return (-1);
	}
	readFile.open(argv[1], fstream::in);
	if (!readFile.is_open())
	{
		cout << "File could not be opened";
		return (-1);
	}
	writeFile.open(string(argv[1]).append(".replace").c_str(), fstream::out);
	while (getline(readFile, readLine))
		writeFile << reconstructString(readLine, argv[2], argv[3]) << endl;
	readFile.close();
	writeFile.close();
	return (0);
}