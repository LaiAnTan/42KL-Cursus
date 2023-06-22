#include "MutantStack.hpp"

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;

template <typename T, typename container>
MutantStack<T, container>::MutantStack()
{
	cout << "MutantStack: Default constructor called" << endl;
}

template <typename T, typename container>
MutantStack<T, container>::MutantStack(const MutantStack<T, container> &mutantstack)
{
	cout << "MutantStack: Copy constructor called" << endl;
	*this = mutantstack;
}

template <typename T, typename container>
MutantStack<T, container> &MutantStack<T, container>::operator = (const MutantStack<T, container> &mutantstack)
{
	cout << "MutantStack: Copy assignment operator called" << endl;
	if (this == &mutantstack)
		return (*this);
	this = mutantstack;
	return (*this);
}

template <typename T, typename container>
MutantStack<T, container>::~MutantStack<T, container>()
{
	cout << "MutantStack: Destructor called" << endl;
}

// returns iterator to the top of the stack
template <typename T, typename container>
typename container::iterator	MutantStack<T, container>::begin(void)
{
	return (this->c.begin());
}

// returns iterator to bottom of stack
template <typename T, typename container>
typename container::iterator	MutantStack<T, container>::end(void)
{
	return (this->c.end());
}