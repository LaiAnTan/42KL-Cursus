#include "Array.hpp"

#include <iostream>

using std::endl;
using std::cout;

int main(void)
{
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = 2;
	
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;

	return (0);
}