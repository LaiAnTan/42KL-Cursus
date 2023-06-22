#pragma once

#ifndef MUTANTSTACK_HPP

#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>
#include <algorithm>

template <typename T, class container = std::deque<T> > // default = deque (if unspecified)
class MutantStack: public std::stack<T, container> //inheriting overload of stack to specify underlying container
{
	public:
		typedef typename container::iterator iterator;

		MutantStack();
		MutantStack(const MutantStack<T, container> &mutantstack);
		MutantStack<T, container> &operator = (const MutantStack<T, container> &mutantstack);
		~MutantStack();

		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif