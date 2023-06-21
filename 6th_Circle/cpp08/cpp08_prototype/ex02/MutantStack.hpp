#pragma once

#ifndef MUTANTSTACK_HPP

#define MUTANTSTACK_HPP

#include <vector>
#include <algorithm>

template <typename T, typename Iter>
class MutantStack
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &mutantstack);
		MutantStack &operator = (const MutantStack &mutantstack);
		~MutantStack();

		T		top(void);
		void	empty(void);
		size_t	size(void);

		void	push(T element);
		void	emplace(T element);
		void	push_range(Iter &begin, Iter &end);
		void	pop(void);
		void	swap(MutantStack &toswap);

		Iter	begin(void);
		Iter	end(void);

	private:
		std::vector<T>	stack;
};

#include "MutantStack.tpp"

#endif