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
	this->ptr = new T();
	this->size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	cout << "Array: Constructor called" << endl;
	this->ptr = new T(n);
	this->size = n;
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
	this->ptr = new T();
	this->size = array.getSize();
}

template <typename T>
Array<T>::~Array()
{
	cout << "Array: Destructor called" << endl;
}

template <typename T>
unsigned int	Array<T>::getSize() const
{
	return (size);
}

template <typename T>
T	&Array<T>::operator [] (unsigned int index)
{
	cout << "Array: subscript operator called" << endl;
}