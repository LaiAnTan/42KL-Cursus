#pragma once

#ifndef MUTANTSTACK_HPP

#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>
#include <algorithm>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator; //container_type specifies the type of underlying container in stack

		MutantStack();
		MutantStack(const MutantStack<T> &mutantstack);
		MutantStack<T> &operator = (const MutantStack<T> &mutantstack);
		~MutantStack();

		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif