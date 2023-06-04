#include "Array.hpp"

#include <iostream>

using std::endl;
using std::cout;

int main(void)
{
	try
	{
		Array<int>		intArray = Array<int>(10);
		Array<string>	strArray = Array<string>(2);

		

		intArray[0] = 2;
		cout << intArray[0] << endl;
		cout << intArray[1] << endl;
		cout << "Size of int array: " << intArray.size() << endl;

		cout << strArray[0] << endl;
		strArray[0] = "Foo bar baz";

		Array<string>	strArray2(strArray);
		strArray2[0] = "Different text goes here";
		cout << strArray2[0] << endl;
		cout << strArray[0] << endl;
		
	}
	catch(const std::exception& e)
	{
		cout << e.what() << endl;
	}

	return (0);
}