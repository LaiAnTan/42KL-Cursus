#include <iostream>
#include <string>

using	std::cout;
using	std::endl;
using	std::string;

int main(void)
{
	string	str = "HI THIS IS BRAIN";
	string	*stringPTR = &str;
	string	&stringREF = str;

	cout << "Memory address of variable str: " << &str << endl;
	cout << "Memory address of pointer to variable str:" << &stringPTR << endl;
	cout << "Memory address of reference to variable str:" << &stringREF << endl;
	cout << endl;
	cout << "Value of variable str: " << str << endl;
	cout << "Value pointed by stringPTR: " << *stringPTR << endl;
	cout << "Value pointed by stringREF: " << stringREF << endl;

	delete stringPTR;
}

/*
pointers are a seperate variable that must be freed.
they hold the address to the variable pointed to it.

references are aliases to the variable referenced.
they are bound to the variable and have the same lifespan as it.
they cannot be reassigned and has the same address and the variable itself
*/
