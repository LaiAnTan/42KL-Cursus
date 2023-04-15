#include "Array.hpp"

#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::exception;

template <typename T>
Array<T>::Array()
{
	cout << "Array: Default constructor called" << endl;
	this->ptr = new T[0];
	this->arraySize = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	cout << "Array: Constructor called" << endl;
	this->ptr = new T[n];
	this->arraySize = n;
}

template <typename T>
Array<T>::Array(const Array &array)
{
	cout << "Array: Copy constructor called" << endl;
	*this = array;
}

template <typename T>
Array<T> &Array<T>::operator = (const Array &array)
{
	cout << "Array: Copy assignment operator called" << endl;
	if (this == &array)
		return (*this);
	this->ptr = new T[array.size()];
	this->arraySize = array.size();
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	cout << "Array: Destructor called" << endl;
	delete []ptr;
	
}

/*
dont forget this:

use delete []pointer for stuff allocated with new[]

delete (no subscript operator) for singular objects;
*/

template <typename T>
T	&Array<T>::operator [] (unsigned int index)
{
	cout << "Array: subscript operator called" << endl;
	if (index >= size())
		throw (IndexOutOfBoundsException());
	return (ptr[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (arraySize);
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("IndexOutOfBoundsException: Array index is out of bounds");
}