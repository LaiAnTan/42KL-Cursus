#include "MutantStack.hpp"

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;

template <typename T>
MutantStack<T>::MutantStack()
{
	cout << "MutantStack: Default constructor called" << endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &mutantstack)
{
	cout << "MutantStack: Copy constructor called" << endl;
	*this = mutantstack;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack<T> &mutantstack)
{
	cout << "MutantStack: Copy assignment operator called" << endl;
	if (this == &mutantstack)
		return (*this);
	this = mutantstack;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack<T>()
{
	cout << "MutantStack: Destructor called" << endl;
}

// returns iterator to the top of the stack
template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

// returns iterator to bottom of stack
template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}